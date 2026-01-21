#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define OK 0
#define NOT_OK 1
#define N 9

int safe(int sudoku[N][N], int i, int j, int value)
{
    for (int k = 0; k < N; k++)
    {
        if ((k != j) && (value == sudoku[i][k]))
        {
            return 0;
        }
    }
    // Column check
    for (int k = 0; k < N; k++)
    {
        if (k != i && value == sudoku[k][j])
        {
            return 0;
        }
    }
    // 3x3 square check
    int k = i - i % 3;
    int l = j - j % 3;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            int current_k = x + k;
            int current_l = y + l;
            if ((current_k != i || current_l != j) && sudoku[current_k][current_l] == value)
            {
                return 0;
            }
        }
    }
    return 1;
}
int check_sudoku(int sudoku[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int value = sudoku[i][j];
            if (value != 0)
            {
                // Line check
                for (int k = 0; k < N; k++)
                {
                    if (k != j && value == sudoku[i][k])
                    {
                        return NOT_OK;
                    }
                }
                // Column check
                for (int k = 0; k < N; k++)
                {
                    if (k != i && value == sudoku[k][j])
                    {
                        return NOT_OK;
                    }
                }
                // 3x3 square check
                int k = i - i % 3;
                int l = j - j % 3;
                for (int x = 0; x < 3; x++)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        int current_k = x + k;
                        int current_l = y + l;
                        if ((current_k != i || current_l != j) && sudoku[current_k][current_l] == value)
                        {
                            return NOT_OK;
                        }
                    }
                }
            }
        }
    }
    return OK;
}

int generate_sudoku(float p, int sudoku[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sudoku[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            float r = (float)rand() / (float)RAND_MAX;

            if (r <= p)
            {

                int start = rand() % 9 + 1;
                int value = start;
                int placed = 0;
                for (int k = 0; k < 9; k++)
                {
                    if (value > 9)
                        value = 1;

                    if (safe(sudoku, i, j, value))
                    {
                        sudoku[i][j] = value;
                        placed = 1;
                        break;
                    }
                    value++;
                }
                if (!placed)
                {
                    return NOT_OK;
                }
            }
        }
    }
    return OK;
}

int solve_sudoku(int sudoku[N][N], int i, int j)
{
    if (i == N)
        return OK;
    int next_i = i;
    int next_j = j + 1;
    if (next_j == N)
    {
        next_i = i + 1;
        next_j = 0;
    }
    if (sudoku[i][j] != 0)
    {
        return solve_sudoku(sudoku, next_i, next_j);
    }

    int start = rand() % 9 + 1;
    int value = start;
    for (int k = 0; k < 9; k++)
    {
        if (value > 9)
            value = 1;

        if (safe(sudoku, i, j, value))
        {
            sudoku[i][j] = value;
            if (solve_sudoku(sudoku, next_i, next_j) == OK)
                return OK;
            sudoku[i][j] = 0;
        }   
        value++;
    }
    return NOT_OK;
}

int read_sudoku_from_file(const char *filename, int sudoku[N][N])
{
    const int max_line_length = 1024;
    FILE *fp;
    // This is possible in C99
    char line[max_line_length], *token, *endptr;
    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error reading file %s\n", filename);
        return NOT_OK;
    }
    int i = 0;
    while (fgets(line, max_line_length, fp) != NULL)
    {
        int j = 0, n;
        token = strtok(line, ", ");
        while (token != NULL && token[0] != '\n')
        {
            n = strtol(token, &endptr, 10);
            sudoku[i][j] = n;
            if (n < 0 || n > 9)
            {
                // Error
                fprintf(stderr, "Unrecognized number at location %d, %d\n", i,
                        j);
                fclose(fp);
                return NOT_OK;
            }
            token = strtok(NULL, ", ");
            j++;
        }
        if (j != 9)
        {
            // Error
            fprintf(stderr, "Something when wrong when reading the sudoku\n");
            fclose(fp);
            return NOT_OK;
        }
        i++;
        // Ignore any extra lines
        if (i == 9)
        {
            break;
        }
    }
    if (i != 9)
    {
        // Error
        fprintf(stderr, "Something when wrong when reading the sudoku\n");
        fclose(fp);
        return NOT_OK;
    }
    fclose(fp);
    return OK;
}

void print_sudoku(int sudoku[N][N]) {
    for (int i = 0 ; i < N ; i++) {
        for (int j = 0 ; j < N ; j++) {
            printf("%d  ",sudoku[i][j]);
        }
        printf("\n");
    }
}

void save_sudoku_to_file(int sudoku[N][N], const char* filename) {
    FILE *fp = fopen(filename, "w");
    if(!fp) {
        printf("Error saving file.\n");
        return;
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            fprintf(fp, "%d%s", sudoku[i][j], (j == N - 1) ? "" : ",");
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Sudoku saved to %s\n", filename);
}

int main() {
    srand((unsigned int)time(NULL));
    
    int sudoku[N][N];
    char option;

    printf("Welcome to Sudoku! What would you like to do?\n");
    while (1) {
        printf("1. Generate a sudoku\n");
        printf("2. Check if a solution is correct\n");
        printf("3. Solve a sudoku\n");
        printf("Choose option (q to quit): ");

        scanf(" %c",&option);
        char c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        
        if (option == 'q') {
            printf("Bye!\n");
            break;
        } else if (option == '1') {
            float p;
            printf("What is the prefill probability (0 < p < 1)? ");
            
            scanf("%f", &p);
            
            int attempts = 0;

            while(attempts < 1000) {
                if(generate_sudoku(p, sudoku) == OK) break;
                attempts++;
            }

            if (attempts < 1000) {
                print_sudoku(sudoku);
                save_sudoku_to_file(sudoku, "generated.csv");
            } else {
                printf("Failed to generate valid sudoku.\n");
            }
        } else if (option == '2') {
            char filename[256];
            printf("Filename: ");
            scanf("%s",filename);
        
            if (read_sudoku_from_file(filename,sudoku) == OK) {
                if (check_sudoku(sudoku) == OK) {
                    printf("Sudoku is OK\n");
                } else {
                    printf("Sudoku is NOT Valid\n");
                }
            }
        } else if (option == '3') {
            char filename[256];
            printf("Filename: ");
            scanf("%s",filename);
        
            if (read_sudoku_from_file(filename,sudoku) == OK) {
                printf("Starting sudoku:\n");
                print_sudoku(sudoku);

                if (solve_sudoku(sudoku,0,0) == OK) {
                    printf("Solved Sudoku:\n");
                    print_sudoku(sudoku);
                    save_sudoku_to_file(sudoku,"solved.csv");
                } else {
                    printf("Couldn't solve this one :(\n");
                }
            }
        } else {
            printf("Unrecognized option\n");
        }
        printf("\n");
    }
}
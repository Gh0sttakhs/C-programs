#include <stdio.h>
#include <stdlib.h>

int main() {
    int *grades;
    printf("Give me the amount of grades: ");
    int n;
    scanf("%d", &n);
    grades = malloc(n*sizeof(int));
    if (!grades) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0 ; i<n ;i++) {
        printf("Give me grade %d: ", i+1);
        scanf("%d", &grades[i]);
    }

    int passed_count = 0;
    int failed_count = 0;
    for (int i = 0 ; i<n ;i++) {
        if (grades[i] >= 50) {
            passed_count++;
        } else {
            failed_count++;
        }
    }

    printf("Passed: %d\n", passed_count);
    printf("Failed: %d\n", failed_count);

    free( grades);
    return 0;
}
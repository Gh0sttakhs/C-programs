#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_sort(int n, int *x) {
    int i, j, min;
    for (i = 1 ; i < n ; i++) {
        min = i - 1;
        for (j = i ; j < n ; j++) {
            if (x[j] < x[min]) {
                min = j;
            }   
        }
        swap(&x[i - 1], &x[min]);
    }
}

int main() {
    int array[] = {64, 25, 12, 22, 11};
    selection_sort(5, array);
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
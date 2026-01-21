#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubblesort(int n, int *x) {
    int i, j;
    for (i = 1 ; i < n ; i++) {
        for (j = n - 1 ; j >= i ; j--){
            if (x[j - 1] > x[j]) {
                swap(&x[j - 1], &x[j]);
            }
        }
    }
}

int main() {
    int array[] = {64, 25, 12, 22, 11};
    bubblesort(5, array);
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
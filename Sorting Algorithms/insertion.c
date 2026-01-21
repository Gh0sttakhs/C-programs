#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertion_sort(int n, int *x) {
    int i, j;
    for (i = 1 ; i < n ; i++) {
        j = i - 1;
        while (j >= 0 && x[j] > x[j+1]){
            swap(&x[j],&x[j+1]);
            j--;
        }
    }
}

int main() {
    int array[] = {64, 25, 12, 22, 11};
    insertion_sort(5, array);
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
#include <stdio.h>

void quicksort(int *x, int lower, int upper)
{
    if (lower < upper)
    {
        int pivot = x[(lower + upper) / 2];
        int i, j;
        for (i = lower, j = upper; i <= j;)
        {
            while (x[i] < pivot)
                i++;
            while (x[j] > pivot)
                j--;
            if (i <= j)
                swap(&x[i++], &x[j--]);
        }
        quicksort(x, lower, j);
        quicksort(x, i, upper);
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
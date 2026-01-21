#include <stdio.h>

int binary(int *array, int key, int n){
    int start = 0;
    int mid, found = 0;
    int end = n - 1;
    while (start <= end) {
        mid = (start + end) / 2;
        if (array[mid] == key) {
            found = 1;
            break;
        } else if (array[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    if (found) {
        printf("Key:%d was found inside the array.\n",key);
    } else {
        printf("Key:%d was NOT found inside the array.\n",key);
    }
    return 0;
}
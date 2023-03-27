#include "../inc/libmx.h"

void mx_sort(int *arr, int size, bool (*f)(int, int)) {

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size - 1; j++) {

            if ( f(arr[j], arr[j + 1]) ) {
                
                int x = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = x;
            }
        }
    }
}


#include "../libmx/inc/libmx.h"

// 
int mx_sort_strarr(char*** strarr) {

    if (strarr == NULL || *strarr == NULL) {
        return -1;
    }
    /*int size = 0;
    for ( ; (*strarr)[size] != NULL; ) {
        size++;
    }*/
    int quit = 0;
    int cnt = 0;
    while (!quit) {
        quit = 1;
        for (int i = 0; /*i < size - 1*/(*strarr)[i+1] != NULL; i++) {
            if ( mx_strcmp( (*strarr)[i], (*strarr)[i+1] ) > 0 ) {
                char* temp = (*strarr)[i];
                (*strarr)[i] = (*strarr)[i+1];
                (*strarr)[i+1] = temp;
                quit = 0;
                cnt++;
            }
        }
    }
    return cnt;
}




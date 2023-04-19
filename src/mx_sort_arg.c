#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"
#include <errno.h>

int mx_sort_arg(char** argarr, char** pararr, char*** dirarr, char*** filearr) {
    int dir_cnt = 0;
    int file_cnt = 0;
    for (int i = 0; argarr[i] != NULL; i++) { // find dir / file
        struct stat stat1;
        struct stat stat2;   
        int erri = lstat( argarr[i], &stat1 );
        int erri2 = stat( argarr[i], &stat2 );

        if ((erri == -1 && true) || (erri2 == -1 && errno != 2)) {

            continue;
        }

        if (S_ISLNK(stat1.st_mode)) {
            if (mx_check_par(pararr, 'l')) {
                file_cnt++;
            }
            else {
                if (S_ISDIR(stat2.st_mode)) {
                    dir_cnt++;
                }
                else {
                    file_cnt++;
                }
            }
        }
        else if (S_ISDIR(stat1.st_mode)) {
            dir_cnt++;
        }
        else {
            file_cnt++;
        }
    }
    
    if (dir_cnt != 0) {
        (*dirarr) = (char**)malloc(sizeof(char*) * (dir_cnt + 1));
        (*dirarr)[dir_cnt] = NULL;
    }
    if (file_cnt != 0) {
        (*filearr) = (char**)malloc(sizeof(char*) * (file_cnt + 1));
        (*filearr)[file_cnt] = NULL;
    }

    int dir_i = 0;
    int file_i = 0;
    for (int i = 0; argarr[i] != NULL; i++) { // find dir / file 

        struct stat stat1;
        struct stat stat2;   
        int erri = lstat( argarr[i], &stat1 );
        int erri2 = stat( argarr[i], &stat2 );

        if ((erri == -1 && true) || (erri2 == -1 && errno != 2)) {

            continue;
        }
        
        if ( S_ISLNK(stat1.st_mode) ) {
            if (mx_check_par(pararr, 'l')) {
                (*filearr)[file_i] = mx_strdup( argarr[i]);
                file_i++;
            }
            else {
                if (S_ISDIR(stat2.st_mode)) {
                    (*dirarr)[dir_i] = mx_strdup(argarr[i]);
                    dir_i++;
                }
                else {
                    (*filearr)[file_i] = mx_strdup(argarr[i]);
                    file_i++;
                }
            }
        }
        else if (S_ISDIR(stat1.st_mode)) {
            (*dirarr)[dir_i] = mx_strdup(argarr[i]);
            dir_i++;
        }
        else {
            (*filearr)[file_i] = mx_strdup(argarr[i]);
            file_i++;
        }
    }
    // sort dir / file 
    if (dirarr != NULL) {
        mx_bubble_sort(*dirarr, dir_cnt);
    }
    if (filearr != NULL) {
        mx_bubble_sort(*filearr, file_cnt);
    }
    return 0;
}


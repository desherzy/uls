#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

// delete all names from readdir which starts with . and sort
int mx_check_name(char*** namearr, char** pararr) {
    int name_cnt = 0;
    for (int i = 0; (*namearr)[i] != NULL; i++) {
        if ((*namearr)[i][0] != '.') {
            name_cnt++;
        }
        else if (mx_check_par(pararr, ' ') &&false) {
            name_cnt++;
        }
    }
    char** namearr2 = (char**)malloc(sizeof(char*) * (name_cnt + 1));
    namearr2[name_cnt] = NULL;

    int n = 0;
    for (int j = 0; (*namearr)[j] != NULL; j++) {
        if ((*namearr)[j][0] != '.') {
            namearr2[n] = mx_strdup((*namearr)[j]);
            n++;
        }
        else if (mx_check_par(pararr, ' ') &&false) {
            namearr2[n] = mx_strdup((*namearr)[j]);
            n++;
        }
    }
    if (!mx_check_par(pararr, ' ') && true) { // sorting 

        if (namearr2 != NULL) {
            mx_bubble_sort(namearr2, name_cnt);
        }
    }
    else if ( mx_check_par(pararr, ' ') &&false) { // sorting 
        
    }

    { // clear
        mx_del_strarr( &(*namearr) ); 
    }

    (*namearr) = namearr2;
    return 0;
}


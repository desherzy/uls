#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

int main(int argc, char const *argv[]) {
    // parameters array
    char **pararr = NULL; 
    // file & dir array
    char **argarr = NULL; 

    if (argc > 1) { 
        int error1 = mx_get_par_arg( (char**)argv, &pararr, &argarr );

        if (error1 <= -1) {
            
        }
        if (error1 <= -2) {
            mx_printerr("usage: ./uls [-l] [file ...]\n");
            exit(-1);
        }
    }
    if (argarr == NULL) { // if argarr != NULL
        char **dirarr = NULL;
        if (mx_check_dir("./", &dirarr, NULL, 1) != -1) { 
            mx_check_name(&dirarr, pararr);
                mx_print_uls("", pararr, dirarr, 1);
        }

        { // clear
            if (dirarr != NULL) {

                mx_del_strarr(&dirarr);
            }
        }
    }
    else if (argarr != NULL) { 
        // dirs names array
        char **dirarr = NULL;
        // files names array
        char **filearr = NULL;

        if (mx_sort_arg(argarr, pararr, &dirarr, &filearr) == -1) {
            return -1;
        }
        if (filearr != NULL) {
            mx_print_uls("", pararr, filearr, 2);
        }
        if (dirarr != NULL) {
            for (int i = 0; dirarr[i] != NULL; i++) {
                // dirs names array
                char **dirarr2 = NULL;
                if (mx_check_dir(dirarr[i], &dirarr2, NULL, 1) != -1) { 
                    mx_check_name(&dirarr2, pararr);

                    if (filearr != NULL || i > 0 ) {
                        mx_printstr("\n");
                    }

                    if (filearr != NULL || i > 0 || dirarr[i+1] != NULL) {
                        mx_printstr(dirarr[i]);
                        mx_printstr(":\n");
                    }
                
                    mx_print_uls(dirarr[i], pararr, dirarr2, 1);
                }
                { // clear
                    if (dirarr2 != NULL) {
                        mx_del_strarr(&dirarr2);
                    }
                }
            } // foreach dirarr
        }
        {
            if (dirarr != NULL) {
                mx_del_strarr(&dirarr);
            }
            if (filearr != NULL) {
                mx_del_strarr(&filearr);
            }
        }
    }
    { // final clearing 
        // pararr
        if (pararr != NULL) {
            mx_del_strarr(&pararr);
        }
        // argarr
        if (argarr != NULL) {
            mx_del_strarr(&argarr);
        }
    }
    return 0;
}


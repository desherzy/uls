#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

// delete all names from readdir which starts with . 
int mx_get_par_arg(char** argv, char*** pararr, char*** argarr) {
    bool is_par_checked = false; // arr if par > 1
    int par_cnt = 0;
    int arg_cnt = 0;
    bool arg_b = false;
    int par = 1;
    for (int i = 1; argv[i] != NULL; i++) { 
        if (argv[i][0] == '-' && argv[i][1] != '\0' && i <= par) {
            for (int j = 1; argv[i][j] != '\0'; j++) {
                if (argv[i][j] == 'l') {
                    if (!(is_par_checked)) {
                        (is_par_checked) = true;
                        par_cnt++;
                        par++;
                    }
                }
                else  {
                    mx_printerr("uls: ");
                    mx_printerr(" illegal option -- ");
                    write(2, &argv[i][j], 1);
                    mx_printerr("\n");

                    return -2;
                }
            }
        }
        else {
            arg_b = true;
            struct stat stat1;
            int err = stat(argv[i], &stat1);
            if ( err < 0 ) {
                {
                    mx_printerr("uls: ");
                    mx_printerr(argv[i]);
                    mx_printerr(": No such file or directory\n");
                }
            }
            else {
                arg_cnt++;
            }
        }
    }
    if (par_cnt != 0) {
        (*pararr) = (char**)malloc((par_cnt + 1) * sizeof(char*));
        (*pararr)[0] = NULL;
        (*pararr)[par_cnt] = NULL;
    }
    if (arg_cnt != 0 || arg_b == true) {
        (*argarr) = (char**)malloc((arg_cnt + 1) * sizeof(char*));
        (*argarr)[arg_cnt] = NULL;
    }
    int par_i = 0;
    int arg_i = 0;
    for (int i = 1; argv[i] != NULL; i++) {
        if (argv[i][0] == '-' && i == 1) {
            for (int j = 1; argv[i][j] != '\0'; j++) {
                if ((*pararr)[0] == NULL && argv[i][j] == 'l') {
                    (*pararr)[par_i] = mx_strnew(1);
                    (*pararr)[par_i][0] = argv[i][j];
                    par_i++;
                }
                else if (argv[i][j] != 'l' && argv[i][j] != '\0') {

                }
            }
        }
        else {
            struct stat stat1;
            int err = lstat(argv[i], &stat1);
            if (err >= 0) {
                (*argarr)[arg_i] = mx_strdup(argv[i]);
                arg_i++;
            }
        }
    }
    return 0;
}


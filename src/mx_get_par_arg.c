#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

// delete all names from readdir which starts with . 
int mx_get_par_arg(char** argv, char*** pararr, char*** argarr) {

    bool is_par_checked = false; // arr if par > 1
    int par_cnt = 0;
    int arg_cnt = 0;
    bool arg_b = false;
    for (int i = 1; argv[i] != NULL; i++) { // foreach in argv // 

        if ( argv[i][0] == '-' && argv[i][1] != '\0' && i == 1 ) {

//write(1, " 13 ", 5);
            for (int j = 1; argv[i][j] != '\0'; j++) {

                if ( argv[i][j] == 'l' ) {

                    if ( !(is_par_checked) ) {

                        (is_par_checked) = true;
                        par_cnt++;
                    }
                }
                else  {
                    mx_printerr("uls: ");
                    mx_printerr(" illegal option -- ");
                    write( 2, &argv[i][j], 1);
                    mx_printerr("\n");

                    // clear?
                    return -2;
                }
            }
        }
        else {
            arg_b = true;
//write(1, " 14 ", 5);
            struct stat stat1;
            int err = stat(argv[i], &stat1);
//write(1, " 15 ", 5);
            if ( err < 0 ) {
//write(1, " 16 ", 5);
                {
                    mx_printerr("uls: ");
                    mx_printerr(argv[i]);
                    mx_printerr(": No such file or directory\n");
                    //exit(-1);
                }
            }
            else {
//write(1, " 17 ", 5);
                arg_cnt++;
            }
        }
    }
//write(1, " 18 ", 5);
    /*write(1, " 15 ", 5);
    write(1, "\npc ", 5);
    mx_printint(par_cnt);
    write(1, " ac ", 5);
    mx_printint(arg_cnt);*/
    if ( par_cnt != 0 ) {
        (*pararr) = (char**)malloc( (par_cnt + 1) * sizeof(char*) );
        (*pararr)[0] = NULL;
        (*pararr)[par_cnt] = NULL;
    }
    if ( arg_cnt != 0 || arg_b == true ) {
        (*argarr) = (char**)malloc( (arg_cnt + 1) * sizeof(char*) );
        (*argarr)[arg_cnt] = NULL;
    }

    int par_i = 0;
    int arg_i = 0;
    for (int i = 1; argv[i] != NULL; i++) { // foreach in argv // 

    //write(1, " 16 ", 5);
        if ( argv[i][0] == '-' && i == 1 ) {

    //write(1, " 161", 5);
            for (int j = 1; argv[i][j] != '\0'; j++) {

    //write(1, " 17 ", 5);
                if ((*pararr)[0] == NULL && argv[i][j] == 'l') {

//write(1, "  pararr ", 10);
                    (*pararr)[par_i] = mx_strnew(1);
                    (*pararr)[par_i][0] = argv[i][j];
                    par_i++;
                }
                else if ( argv[i][j] != 'l' && argv[i][j] != '\0' ) { // error // print usage (-1)


                }

//write(1, " 182 ", 6);
            }
        }
        else {
    /*write(1, " 162", 5);
    write(1, " ai ", 5);
    mx_printint(arg_i);*/
            struct stat stat1;
            int err = lstat(argv[i], &stat1);
            if ( err >= 0 ) {
                (*argarr)[arg_i] = mx_strdup( argv[i] );
                arg_i++;
//write(1, "  argarr ", 10);
            }
        }
    }
    
//write(1, " 199 ", 6);
    return 0;
}




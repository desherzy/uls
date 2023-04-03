#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"
#include <errno.h>

int mx_sort_arg(char** argarr, char** pararr, char*** dirarr, char*** filearr ) {
    //char ** argarr2 = NULL;

    int dir_cnt = 0;
    int file_cnt = 0;
    for (int i = 0; argarr[i] != NULL; i++) { // find dir / file | other sort in dir/file

        struct stat stat1;
        struct stat stat2;   
        int erri = lstat( argarr[i], &stat1 ); //stat free?
        int erri2 = stat( argarr[i], &stat2 ); // free?
        if ((erri == -1 && true) || (erri2 == -1 && errno != 2)) {
            mx_printerr("\n   e1   ");
            mx_printint(erri);
            mx_printerr("   e2   ");
            mx_printint(erri2);
            mx_printerr("   errno   ");
            mx_printint( errno );
            mx_printerr("   name   ");
            mx_printerr(argarr[i]);
            mx_printerr("              ===================== continue\n");
            if ( false ) { // check errno
                mx_printerr("usage: ./uls [-l] [file ...]\n");
                exit(-1);
            }
            else if ( false ) {
                mx_printerr("usage: ./uls [-l] [file ...]\n");
                exit(-1);
            }
            continue;
        }

mx_printstr( argarr[i] );
mx_printstr( "   m1l " );
mx_printint( stat1.st_mode );
mx_printstr( "   m2 " );
mx_printint( stat2.st_mode );

        /*if ( S_ISLNK(stat2.st_mode) ) {
mx_printstr( "   l" );
        }
        else if ( S_ISREG(stat2.st_mode) ) {
mx_printstr( "   f" );
        }
        else if ( S_ISDIR(stat2.st_mode) ) {
mx_printstr( "   d" );
        }*/

        if ( S_ISLNK(stat1.st_mode) ) {

mx_printstr( "   l" );
            if ( mx_check_par(pararr, 'l') ) {
                
                /*lstat( link, &stat2 ); // free?
                if ( S_ISREG(stat2.st_mode)) {
mx_printstr( "   d" );

                }
                else if ( S_ISDIR(stat2.st_mode) ) {
mx_printstr( "   f" );

                }*/
mx_printstr( "   1f" );
                file_cnt++;
            }
            else {
                
                //stat( argarr[i], &stat1 ); //stat// free?
//mx_printstr( "   mode2 " );
//mx_printint( stat1.st_mode );
//
                if ( S_ISREG(stat2.st_mode) ) {
mx_printstr( "   2f" );
                    file_cnt++;
                }
                else if ( S_ISDIR(stat2.st_mode) ) {
mx_printstr( "   2d" );
                    dir_cnt++;
                }
            }
        }
        else if ( S_ISREG(stat1.st_mode) ) {
mx_printstr( "   f" );
            file_cnt++;
        }
        else if ( S_ISDIR(stat1.st_mode) ) {
mx_printstr( "   d" );
            dir_cnt++;
        }
mx_printstr( "   \n" );
    }
    //return 0;
    if ( dir_cnt != 0 ) {
        (*dirarr) = (char**)malloc( sizeof(char*) * (dir_cnt + 1) );
        (*dirarr)[dir_cnt] = NULL;
    }
    if ( file_cnt != 0 ) {
        (*filearr) = (char**)malloc( sizeof(char*) * (file_cnt + 1) );
        (*filearr)[file_cnt] = NULL;
    }
    int dir_i = 0;
    int file_i = 0;
    for (int i = 0; argarr[i] != NULL; i++) { // find dir / file 

        struct stat stat1;
        struct stat stat2;   
        int erri = lstat( argarr[i], &stat1 ); // free?
        int erri2 = stat( argarr[i], &stat2 ); //stat free?
        if ((erri == -1 && true) || (erri2 == -1 && errno != 2)) {
            
                mx_printerr("\n              ===================== continue\n");
            if ( false ) { // check errno
                mx_printerr("usage: ./uls [-l] [file ...]\n");
                exit(-1);
            }
            else if ( false ) {
                mx_printerr("usage: ./uls [-l] [file ...]\n");
                exit(-1);
            }
            continue;
        }
        
        if ( S_ISLNK(stat1.st_mode) ) {

            if ( mx_check_par(pararr, 'l') ) {
                
                (*filearr)[file_i] = mx_strdup( argarr[i] );
                file_i++;
            }
            else {

                if ( S_ISREG(stat2.st_mode) ) {

                    (*filearr)[file_i] = mx_strdup(argarr[i]);
                    file_i++;
                }
                else if ( S_ISDIR(stat2.st_mode) ) {

                    (*dirarr)[dir_i] = mx_strdup(argarr[i]);
                    dir_i++;
                }
            }
        }
        else if ( S_ISREG(stat1.st_mode) ) {

            (*filearr)[file_i] = mx_strdup(argarr[i]);
            file_i++;
        }
        else if ( S_ISDIR(stat1.st_mode) ) {

mx_printstr( " dc :   " );
mx_printstr( argarr[i] );
mx_printstr( "    " );

            (*dirarr)[dir_i] = mx_strdup(argarr[i]);

mx_printstr( (*dirarr)[dir_i] );
mx_printstr( "   \n " );

            dir_i++;
        }
    }
    { // sort dir / file 
mx_printstr( " \ndbs1 :   " );
for (int i = 0; (*dirarr)[i] != NULL; i++) {
//write(1, " 021", 5);
    mx_printstr( (*dirarr)[i] );
    mx_printstr( " | " );
}
mx_printstr( " \ndbs :   " );
        mx_print_strarr( *dirarr," | ");
mx_printstr( " fbs :   " );
        mx_print_strarr( *filearr," | ");

        mx_sort_strarr(dirarr);
        mx_sort_strarr(filearr);

mx_printstr( " das :   " );
        mx_print_strarr( (*dirarr)," | ");
mx_printstr( " fas :   " );
        mx_print_strarr( (*filearr)," | ");
    }
    return 0;
}




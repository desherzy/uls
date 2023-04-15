#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

// 
int mx_check_dir( char* dirname, char*** dirarr, char*** filearr, int type ) {
    
    //filearr = NULL;
    //dirname = NULL;
    //dirarr = NULL;
    DIR *dir;
    dir = opendir( dirname );

    if ( dir != NULL ) {

        struct dirent *dirnt;
        dirnt = readdir( dir );

        int dir_cnt = 0;
        int file_cnt = 0;
        //char* name = readdir( dir );
        while ( dirnt != NULL ) { // count all files and 

            if ( type == 1 ) { // return all names in dirarr
                /*DIR *cdir = opendir( "./" );
                if ( cdir == NULL ) { // if file
                    closedir( cdir );
                    dir_cnt++;
                }
                else if  ( 0 ) { // if dir 
                    dir_cnt++;
                }
                if ( 0 ) { // if link
                    dir_cnt++;
                }*/
                if ( true ) { // if else
                    dir_cnt++;
                }
                else if ( false ) {
                    file_cnt++;
                }
            }
            else if ( false && type == 2 ) { // for -R 

            }
            dirnt = readdir( dir );
        }
        closedir( dir );

        // malloc new dirarr & filearr
        if ( dir_cnt != 0 ) {
            (*dirarr) = (char**)malloc( sizeof(char*) * (dir_cnt + 1) );
            (*dirarr)[dir_cnt] = NULL;
        }
        if ( file_cnt != 0 ) {
            (*filearr) = (char**)malloc( sizeof(char*) * (file_cnt + 1) );
            (*filearr)[file_cnt] = NULL;
        }
//mx_printstr(" dirc ");
//mx_printint(dir_cnt);

        dir = opendir( dirname );
        dirnt = readdir( dir );

        int dir_i = 0;
        //int file_i = 0;
        while (dirnt != NULL) {

            if ( type == 1 ) { // return all names in dirarr 

                
                if (dir_i < dir_cnt) {
                    (*dirarr)[dir_i] = mx_strdup( dirnt->d_name );
                    dir_i++;
                } 
                else if (false){

                    //file_i++;
                }
            }
            else if ( false && type == 2 ) { // 
                
            }

            dirnt = readdir( dir );
        }
//mx_printstr(" diri ");
//mx_printint(dir_i);
//mx_printstr("\n");
        closedir( dir );
    }
    else { // dir not opened 
        // print not open error

        // print no file error
        return -1;
    }
    return 0;
}




#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

int mx_check_dir(char* dirname, char*** dirarr, char*** filearr, int type) {
    DIR *dir;
    dir = opendir(dirname);

    if (dir != NULL) {
        struct dirent *dirnt;
        dirnt = readdir(dir);

        int dir_cnt = 0;
        int file_cnt = 0;
        while (dirnt != NULL) {
            if (type == 1) { // return all names in dirarr
                if (true) {
                    dir_cnt++;
                }
                else if (false) {
                    file_cnt++;
                }
            }
            else if (false && type == 2) { 

            }
            dirnt = readdir(dir);
        }
        closedir(dir);
        
        if (dir_cnt != 0) {
            (*dirarr) = (char**)malloc(sizeof(char*) * (dir_cnt + 1));
            (*dirarr)[dir_cnt] = NULL;
        }
        if (file_cnt != 0) {
            (*filearr) = (char**)malloc(sizeof(char*) * (file_cnt + 1));
            (*filearr)[file_cnt] = NULL;
        }
        dir = opendir(dirname);
        dirnt = readdir(dir);

        int dir_i = 0;
        while (dirnt != NULL) {
            if (type == 1) {
                if (dir_i < dir_cnt) {
                    (*dirarr)[dir_i] = mx_strdup(dirnt->d_name);
                    dir_i++;
                } 
            }
            else if (false && type == 2) { 
                
            }
            dirnt = readdir( dir );
        }
        closedir( dir );
    }
    else {
        return -1;
    }
    return 0;
}


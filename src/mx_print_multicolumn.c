#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

int mx_print_multicolumn(char** printarr, char** pararr) {
    // space between cols 
    char* space = "\t";
    int widht = 0;
    { // get terminal cols 
        struct winsize ws;
        ioctl(0, TIOCGWINSZ, &ws);
        widht = ws.ws_col;
    }
    int print_cnt = 0;
    for ( ; printarr != NULL && printarr[print_cnt] != NULL; ) { 
        print_cnt++; 
    }
    int rows = 1; // rows count
    int max_col_len = 0;
    { // find count of rows 
        for (int ni = 0; printarr != NULL && printarr[ni] != NULL; ni++) { // col widht
            if (mx_strlen(printarr[ni]) + (8 - mx_strlen(printarr[ni]) % 8) > max_col_len) {
                max_col_len = mx_strlen(printarr[ni]) + (8 - mx_strlen(printarr[ni]) % 8);
            }
        }
        for (; rows <= print_cnt ; rows++) {
            int max_row_len = print_cnt / rows;
            if (print_cnt % rows > 0) {
                max_row_len += 1;
            }

            max_row_len *= max_col_len;

            if (max_row_len <= widht) { // if row len <= terminal len
                break;
            }
            else {
                max_row_len = 0;
            }
        }
    }
    { // print 
        int rows_i = 0;
        for (; rows_i < rows; rows_i++) { // foreach row
            
            bool b = false;
            for (int cols_i = 0; cols_i*rows + rows_i < print_cnt ; cols_i++) { // foreach col
                { // print 
                    b = true;

                    mx_printstr(printarr[(cols_i*rows + rows_i)]);

                    if ((cols_i + 1) * rows + rows_i < print_cnt) {
                        for (int j = (mx_strlen(printarr[(cols_i*rows + rows_i)])); j < max_col_len; j+=(8 - j % 8)) {
                            mx_printstr( space );
                        }
                    }
                    else if (mx_check_par(pararr, ' ')) {
                        
                    }
                }
            }
            if (b) {
                mx_printstr("\n");
            }
        }
    }
    return 0;
}


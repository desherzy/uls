#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

int mx_print_multicolumn(char** printarr, char** pararr) {

//mx_printstr("\n print  mco  \n");
    // space between cols 
    char* space = "\t";
    //int space_len = 8; // without \0 
    int widht = 0;
    { // get terminal cols 
        struct winsize ws;
        ioctl(0, TIOCGWINSZ, &ws);
        widht = ws.ws_col;
    }
mx_printstr("\nwidht: ");
mx_printint(widht);
mx_printstr("| ");

    int print_cnt = 0;
    for ( ; printarr != NULL && printarr[print_cnt] != NULL; ) { 
        print_cnt++; 
    }
    // int* intarr = NULL; 
    // {
    //     for ( ; printarr[print_cnt] != NULL ; print_cnt++) {  }
    //     intarr = (int *)malloc( sizeof(int) * print_cnt ); 
    //     for (int i = 0; i < print_cnt; i++) {

    //         intarr[i] = mx_strlen(printarr[i]);
    //     }
    // }
/*mx_printstr(" 045-2 ");
mx_printstr("\n print_cnt         ");
mx_printint(print_cnt);*/

    int rows = 1; // rows count
    int max_col_len = 0;
    { // find count of rows 
        for (int ni = 0; printarr != NULL && printarr[ni] != NULL; ni++) { 
            
            if ( mx_strlen(printarr[ni]) + (8 - mx_strlen(printarr[ni]) % 8) > max_col_len ) {

                max_col_len = mx_strlen(printarr[ni]) + (8 - mx_strlen(printarr[ni]) % 8);
            }
        }
mx_printstr("\n max_col_len         ");
mx_printint(max_col_len);
mx_printstr(" \n");

        for ( ; rows <= print_cnt ; rows++) {
            
            int max_row_len = print_cnt / rows;
            if ( print_cnt % rows > 0) {
                max_row_len += 1;
            }
            max_row_len *= max_col_len;

            /*for (int ri = 0; ri < rows; ri++) { // foreach row

                int ri_cols = print_cnt / rows;
                if ( print_cnt % rows > ri) {
                    ri_cols += 1;
                }
                for (; cols_i < ri_cols ; cols_i++) { // foreach col

                    int col_len = 0;
    //mx_printstr(" 045-3 ");
                    for (int row = 0; row < rows && (cols_i*rows + row) < print_cnt; row++) { // find max col name len 


    //mx_printstr(" 045-31 ");
                        if (mx_strlen(printarr[(cols_i*rows + row)]) > col_len) { // (col * 4) + (row)

                            col_len = mx_strlen(printarr[(cols_i*rows + row)]);
                        }
                    }

                    row_len += col_len;
                    // 
                    if (cols_i + 1 < ri_cols) {

                        row_len += 8 - row_len % 8;
                    }
                    // int wtab = 8 - row_len % 8;
                    // if ( row_len % 8 == 0) {

                    //     row_len += space_len;
                    // }
                }
                if (row_len > max_row_len) {
                    max_row_len = row_len;
                    row_len = 0;
                }
            }*/
mx_printstr("\nrows: ");
mx_printint(rows);
mx_printstr("      row_len: ");
mx_printint(max_row_len);
mx_printstr("|\n");


            if (max_row_len <= widht) { // if row len <= terminal len
                break;
            }
            else {
                max_row_len = 0;
            }
        }
    }
/*mx_printstr(" 045-5 ");
mx_printstr("\n rows         ");
mx_printint(rows);
mx_printstr("\n");*/
    { // print 
        int rows_i = 0;
        for (; rows_i < rows; rows_i++) { // foreach row
            
            //int row_len = 0;
            for (int cols_i = 0; cols_i*rows + rows_i < print_cnt ; cols_i++) { // foreach col

                /*int col_len = 0;
                for ( int row = 0; row < rows && (cols_i*rows + row) < print_cnt ; row++) { // find max col len 

                    if ( mx_strlen( printarr[ (cols_i*rows + row) ] ) > col_len ) { // (col * 4) + (row)
                        col_len = mx_strlen( printarr[ (cols_i*rows + row) ] );
                    }
                }*/
                //row_len += col_len;
                //row_len += space_len - 1;
                { // print 
                    mx_printstr( printarr[ (cols_i*rows + rows_i) ] );
                    //mx_printint(  (cols_i*rows + rows_i)  );

                    if ((cols_i + 1) * rows + rows_i < print_cnt) {
                        //for (int j = ( /*col_len -*/ mx_strlen(printarr[ (cols_i*rows + rows_i) ]) ); j < (col_len + (8 - col_len % 8)); j+=(8 - j % 8)) {
                        for (int j = ( /*col_len -*/ mx_strlen(printarr[ (cols_i*rows + rows_i) ]) ); j < max_col_len; j+=(8 - j % 8)) {
                            mx_printstr( space );
                        }
                    }
                    else if (mx_check_par(pararr, ' ')) {
                        
                    }
                }
            }
            mx_printstr("\n");
        }
    }
    { // clear 
       // free( intarr );
    }
//mx_printstr("\n ");
    // printarr cleaned in main
    return 0;
}





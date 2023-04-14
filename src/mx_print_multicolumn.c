#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

int mx_print_multicolumn(char** printarr, char** pararr) {

//mx_printstr("\n print  mco  \n");
    // space between cols 
    char* space = " ";
    int space_len = 3; // without \0 
    int widht = 0;
    { // get terminal cols 
        struct winsize ws;
        ioctl(0, TIOCGWINSZ, &ws);
        widht = ws.ws_col;
    }
    //mx_printstr("\nwidht: ");
    //mx_printint(widht);

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
    { // find count of rows 
        
        for ( ; rows <= print_cnt ; rows++) {
            
            int row_len = 0;
            int cols_i = 0;
            for (; cols_i < print_cnt ;) { // foreach col // find all rows lens

                int col_len = 0;
//mx_printstr(" 045-3 ");
                for (int row = 0; row < rows && (cols_i*rows + row) < print_cnt; row++) { // find max col len 

                    /*for (int stri = 0; printarr[ cols_i  ] != NULL; stri++) {
                        
                    }*/ //
//mx_printstr(" 045-31 ");
                    if (mx_strlen(printarr[(cols_i*rows + row)]) > col_len) { // (col * 4) + (row)
/*mx_printstr(" true ");
mx_printstr(printarr[ (cols_i*rows + row) ]);
mx_printstr("\n");*/
                        col_len = mx_strlen(printarr[(cols_i*rows + row)]);
                    }
                }
/*mx_printstr(" 045-4 ");*/

                row_len += col_len;
                if (cols_i + 1 < print_cnt)
                    row_len += space_len;

                cols_i++;
            }

            //mx_printstr("\nrow_len: ");
            //mx_printint(row_len);

            if (row_len <= widht) { // if row len <= terminal len
                break;
            }
            else {
                row_len = 0;
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
            int cols_i = 0;
            for ( ; cols_i*rows + rows_i < print_cnt ; ) { // foreach col

                int col_len = 0;
                for ( int row = 0; row < rows && (cols_i*rows + row) < print_cnt ; row++) { // find max col len 

                    /*for (int stri = 0; printarr[ cols_i  ] != NULL; stri++) {
                        
                    }*/ //
                    if ( mx_strlen( printarr[ (cols_i*rows + row) ] ) > col_len ) { // (col * 4) + (row)
                        col_len = mx_strlen( printarr[ (cols_i*rows + row) ] );
                    }
                }
                //row_len += col_len;
                //row_len += space_len - 1;
                { // print 
                    mx_printstr( printarr[ (cols_i*rows + rows_i) ] );
                    //mx_printint(  (cols_i*rows + rows_i)  );

                    if ((cols_i + 1) * rows + rows_i < print_cnt) {
                        for (int j = ( /*col_len -*/ mx_strlen(printarr[ (cols_i*rows + rows_i) ]) ); j < (col_len + space_len); j++) {
                            mx_printstr( space );
                        }
                    }
                    else if (mx_check_par(pararr, ' ')) {
                        
                    }
                }
                cols_i++;
            }
            mx_printstr("\n");
        }
    }
    { // clear 
       // free( intarr );
    }
mx_printstr("\n ");
    // printarr cleaned in main
    return 0;
}



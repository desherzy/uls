#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

int main(int argc, char const *argv[]) {
    test();

    // parameters array
    char **pararr = NULL; 
    // file & dir array
    char **argarr = NULL; 

    if (argc > 1) { 
        int error1 = mx_get_par_arg( (char**)argv, &pararr, &argarr );

write(1, " 02 ", 5);
mx_printstr( "\npararr: " );
if (pararr == NULL) write(1, " pn ", 5);
if (argarr == NULL) write(1, " an ", 5);
for (int i = 0; pararr[i] != NULL; i++) {
//write(1, " 021", 5);
    mx_printstr( pararr[i] );
    mx_printstr( " | " );
}
mx_printstr( "\nargarr: " );
for (int i = 0; argarr[i] != NULL; i++) {
    mx_printstr( argarr[i] );
    mx_printstr( " | " );
}
write(1, "\n03\n", 5);

        if ( error1 <= -1 ) {
            
        }
        if ( error1 <= -2 ) {
            mx_printerr("usage: ./uls [-l] [file ...]\n");
            exit(-1);
        }
    } // check if there any arg && get sorted par & arg 
    //return 1;
    if ( argarr == NULL ||true) { // if argarr != NULL

write(1, "\n04\n", 5);
mx_printstr( "argc: " );
mx_printint( argc );
mx_printstr( "\n" );

        // dirs names array
        //char ***printarr = NULL;

        // dirs names array
        char **dirarr = NULL;
        // files names array
        //char **filearr = NULL;

write(1, " 041", 5);
        if ( mx_check_dir( "./", &dirarr, NULL, 1 ) != -1) { 

if (dirarr == NULL) write(1, " dn ", 5);
for (int i = 0; dirarr[i] != NULL; i++) {
//write(1, " 021", 5);
    mx_printstr( dirarr[i] );
    mx_printstr( " | " );
}
write(1, " 042", 5);

            mx_check_name( &dirarr, pararr);

write(1, " 043 \n", 7);
if (dirarr == NULL) write(1, " dn ", 5);
for (int i = 0; dirarr[i] != NULL; i++) {
//write(1, " 021", 5);
    mx_printstr( dirarr[i] );
    mx_printstr( " | " );
}
            /*for (int i = 0; filearr[i] != NULL; i++) {

                mx_check_l( filearr[i], pararr, printarr );
            } // foreach filearr

            for (int i = 0; dirarr[i] != NULL; i++) {

                mx_check_l( dirarr[i], pararr, printarr );
            } // foreach dirarr*/

            //for (int i = 0; dirarr[i] != NULL; i++) {

                mx_print_uls( pararr, dirarr, 1 );
            //}
            /*for (int i = 0; filearr[i] != NULL; i++) {

                mx_print_uls( pararr, filearr, 1 );
            } */// foreach dirarr
write(1, " 046", 5);
        }
        else {
write(1, " 047", 5);

        }
write(1, " 048", 5);
        { // clear


            pararr = NULL; 
            dirarr = NULL; 
            argv = NULL;
        }
write(1, "\n05\n", 5);
    }
    else if ( argarr != NULL ) { // arg ==============================================

write(1, "\n06\n", 5);

        // dirs names array
        char **dirarr = NULL;
        // files names array
        char **filearr = NULL;

        if ( mx_sort_arg( argarr, pararr, &dirarr, &filearr ) ) {

            
        }
        if ( filearr != NULL ) {

            /*for (int i = 0; filearr[i] != NULL; i++) {

                mx_check_l( filearr[i], pararr, printarr );
            } // foreach filearr
            if ( printarr != NULL ) {

            }
            { // clear printarr


            }*/
            mx_print_uls( pararr, filearr, 1 );
        }
        if ( dirarr != NULL ) {

            for (int i = 0; dirarr[i] != NULL; i++) {

                // dirs names array
                char **dirarr2 = NULL;

                if ( mx_check_dir( dirarr[i], &dirarr2, NULL, 1 ) != -1) { 

                    mx_check_name( &dirarr, pararr);

                    mx_printstr( dirarr[i] );
                    mx_printstr( ":\n" );
                    //for (int i = 0; dirarr2[i] != NULL; i++) {

                        mx_print_uls( pararr, dirarr2, 1 );
                    //} // foreach dirarr
                }
                else {


                }
                { // clear


                    pararr = NULL; 
                    dirarr = NULL; 
                    argv = NULL;
                }
            } // foreach dirarr
            { // clear 

                
            }
        }
        {

        }
write(1, "\n07\n", 5);
    }
    { // final clearing 
write(1, "\n08\n", 5);
if ( pararr == NULL ) 
mx_printstr(" pararr-nul1\n");
if ( argarr == NULL ) 
mx_printstr(" argarr-nul2\n");
        /*for (int i2 = 0; i2 < islands_count ; i2++ ) {
            free(varr[i2]);
        }
        free(varr);
        for (int i2 = 0; i2 < islands_count ; i2++ ) {
            free(parr[i2]);
        }
        free(parr);*/
        // pararr
        if (pararr != NULL) {

            mx_del_strarr(&pararr);
        }
        // argarr
        if (argarr != NULL) {

            mx_del_strarr(&argarr);
        }
write(1, "\n09\n", 5);
    }
    return 0;
}





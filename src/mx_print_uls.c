#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

int mx_print_uls(char **pararr, char** namearr, int type ) {

    //pararr = NULL;
    //namearr = NULL;
    //dirname = NULL;
    type = 1;

    if ( mx_check_par(pararr, 'l') ) {

        int sizelen = 1;
        { // find total and size col len
            int total = 0;
            for (int i = 0; namearr[i] != NULL; i++) { // foreach in names
                struct stat stat1;
                int serr = stat( namearr[i], &stat1 ); // free?
                total += stat1.st_blocks;
                serr = mx_strlen( mx_itoa(stat1.st_size) );
                if (serr > sizelen) {
                    sizelen = serr;
                }
            }
            mx_printstr( "total " );
            //mx_printstr( mx_itoa(total) );
            mx_printstr( mx_itoa(total/2) ); // linux ====================================================================================
            mx_printstr( "\n" );
        }
        char** linearr = NULL;
        const int cnt = 10;
        for (int i = 0; namearr[i] != NULL; i++) { // foreach in names

            linearr = (char**)malloc( sizeof(char*) * (cnt + 1) );
            linearr[cnt] = NULL;
            for (int i = 0; linearr[i] != NULL; i++) { // set NULL
                linearr[i] = NULL;
            } // ?

            mx_printstr( mx_get_acl( namearr[i], pararr ) );
            mx_printstr( " " );
            struct stat stat1;
            stat( namearr[i], &stat1 ); // free?

            mx_printstr( " " );
            struct passwd* pwu = getpwuid( stat1.st_uid );
            mx_printstr( pwu->pw_name );
            mx_printstr( " " );
            struct group* grp = getgrgid( stat1.st_gid );
            mx_printstr( grp->gr_name );
            mx_printstr( " " );
            {
                for ( ; false; ) {

                }
                mx_printstr( mx_itoa(stat1.st_size) );
            } // print size
            mx_printstr( " " );
            mx_printstr( mx_get_date( time(&stat1.st_mtime) ) );
            mx_printstr( " " );
            mx_printstr( namearr[i] );
            if ( false ) { // if link 
                mx_printstr( " -> " );
                mx_printstr( "link" );
            }
            mx_printstr("\n");
        }
    
    }
    if ( !mx_check_par(pararr, 'l') ) {

mx_printstr("\n print uls !l    \n");

        if (isatty(1) == 1) {

            mx_print_multicolumn(namearr, pararr);
        }
        else if (isatty(1) == 0) {

mx_printstr("\n print  tty  \n");
            for (int i = 0; namearr[i] != NULL; i++) { // foreach in names

                mx_printstr( namearr[i] );
                mx_printstr("\n");
            }
        }
    }
    { // clear 

    }
    return 0;
}



#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

int mx_print_uls( char* path, char **pararr, char** namearr /*int type*/ ) {

    //pararr = NULL;
    //namearr = NULL;
    //dirname = NULL;
    //type = 1;

//mx_printstr( "                                 l1   \n" );
    if ( mx_check_par(pararr, 'l') ) {

//mx_printstr( " \nprint l :   \n" );
//mx_printstr( "                                 l2   \n" );
//mx_print_strarr( *dirarr," | ");
        char *fullfilename = NULL;
        int sizelen = 1;
        struct stat stat1;
        { // find total and size col len
            int total = 0;

            if (total == 0) { }

            for (int i = 0; namearr[i] != NULL; i++) { // foreach in names
                {
                    int s = mx_strlen(path);
                    fullfilename = mx_strnew(s + mx_strlen(namearr[i]) + 1);
                    mx_strcpy(fullfilename, path);
                    if (s != 0) {
                        fullfilename[s] = '/';
                        s++;
                    }
                    int j = 0;
                    for ( ; namearr[i][j] != '\0' ; s++) {
                        fullfilename[s] = namearr[i][j];
                        j++;
                    }
                }
//mx_printstr( " full file       ");
//mx_printstr( fullfilename);
//mx_printstr( "  ");
                stat( fullfilename, &stat1 ); // path + '/' + namearr[i]

                total += stat1.st_blocks;
                int slen = mx_strlen( mx_itoa(stat1.st_size) );
                if (slen > sizelen) {
                    sizelen = slen;
                }
            }
            //mx_printstr( "total " );
            //mx_printstr( mx_itoa(total) );
            //mx_printstr( mx_itoa(total/2) ); // linux ====================================================================================
            //mx_printstr( "\n" );
        }
//mx_printstr( "                                 l4   \n" );
        char** linearr = NULL;
        const int cnt = 10;
        for (int i = 0; namearr[i] != NULL; i++) { // foreach in names
            {
                int s = mx_strlen(path);
                fullfilename = mx_strnew(s + mx_strlen(namearr[i]) + 1);
                mx_strcpy(fullfilename, path);
                if (s != 0) {
                    fullfilename[s] = '/';
                    s++;
                }
                int j = 0;
                for ( ; namearr[i][j] != '\0' ; s++) {
                    fullfilename[s] = namearr[i][j];
                    j++;
                }
            }
/*mx_printstr( namearr[i] );
mx_printstr( "\n" );
mx_printstr( "                                 l4-1   \n" );*/
/*mx_printstr( "  stat   " );
mx_printstr( namearr[i] );*/

            stat( fullfilename, &stat1 ); // path + '/' + namearr[i]
            linearr = (char**)malloc( sizeof(char*) * (cnt + 1) );
            linearr[cnt] = NULL;
            for (int i = 0; linearr[i] != NULL; i++) { // set NULL
                linearr[i] = NULL;
            } // ?
//mx_printstr( "                                 l4-2   \n" );

            mx_printstr( mx_get_acl( fullfilename, pararr ) );
//mx_printstr( "                                 l4-3   \n" );
            //mx_printstr( " " );
            //struct stat stat1;
            lstat( fullfilename, &stat1 ); // path + '/' + namearr[i]
//mx_printstr( "                                 l5   \n" );

            /*mx_printstr( " " );
            {
                for ( ; false; ) { // space

                }
                mx_printstr( mx_itoa(stat1.st_size) );
            } // print */
            mx_printstr( " " );
            struct passwd* pwu = getpwuid( stat1.st_uid );
            mx_printstr( pwu->pw_name );
            mx_printstr( " " );
            struct group* grp = getgrgid( stat1.st_gid );
            mx_printstr( grp->gr_name );
            mx_printstr( " " );
            {
                for ( ; false; ) { // space

                }
                mx_printstr( mx_itoa(stat1.st_size) );
            } // print size
            mx_printstr( " " );
            mx_printstr( mx_get_date( stat1.st_mtime ) );
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

//mx_printstr("\n print uls !l    \n");

        if (isatty(1) == 1) {

            //mx_print_multicolumn(namearr, pararr);
        }
        else if (isatty(1) == 0) {

//mx_printstr("\n print  tty  \n");
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



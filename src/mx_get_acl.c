#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"
#include <errno.h>

char* mx_get_acl(char *filename, char **pararr) {

    struct stat stat1;
    struct stat stat2;
    lstat( filename, &stat1 ); // free?
    stat( filename, &stat2 ); // free?

    char* acl = mx_strnew(11);
    for(int i = 0; i < 11; i++) {
        acl[i] = '-';
    }
//mx_printstr( "                            acl2   \n" );
    acl[10] = ' ';
    int mode = 0;
    if ( S_ISLNK(stat1.st_mode) ) {

//mx_printstr( " <l> " );
        if ( mx_check_par(pararr, 'l') ) {
            acl[0] = 'l';
//mx_printstr( " <l> " );
            mode = 1;
        }
        else {
            if ( S_ISDIR(stat2.st_mode) ) {
                acl[0] = 'd';
//mx_printstr( " <d> " );
                mode = 2;
            }
            else {
//mx_printstr( " <f> " );
                acl[0] = '-';
                mode = 2;
            }
        }

    }
    else if ( S_ISDIR(stat1.st_mode) ) {
        acl[0] = 'd';
//mx_printstr( " <d> " );
        mode = 1;
    }
    else /*if ( S_ISREG(stat2.st_mode) )*/ {
        acl[0] = '-';
//mx_printstr( " <f> " );
        mode = 1;
    }
    if ( mode == 1 ) {
        if (stat1.st_mode & S_IRUSR) acl[1] = 'r';
        if (stat1.st_mode & S_IWUSR) acl[2] = 'w';
        if (stat1.st_mode & S_IXUSR) acl[3] = 'x';
        if (stat1.st_mode & S_IRGRP) acl[4] = 'r';
        if (stat1.st_mode & S_IWGRP) acl[5] = 'w';
        if (stat1.st_mode & S_IXGRP) acl[6] = 'x';
        if (stat1.st_mode & S_IROTH) acl[7] = 'r';
        if (stat1.st_mode & S_IWOTH) acl[8] = 'w';
        if (stat1.st_mode & S_IXOTH) acl[9] = 'x';
    }
    else if ( mode == 2 ) {
        if (stat2.st_mode & S_IRUSR) acl[1] = 'r';
        if (stat2.st_mode & S_IWUSR) acl[2] = 'w';
        if (stat2.st_mode & S_IXUSR) acl[3] = 'x';
        if (stat2.st_mode & S_IRGRP) acl[4] = 'r';
        if (stat2.st_mode & S_IWGRP) acl[5] = 'w';
        if (stat2.st_mode & S_IXGRP) acl[6] = 'x';
        if (stat2.st_mode & S_IROTH) acl[7] = 'r';
        if (stat2.st_mode & S_IWOTH) acl[8] = 'w';
        if (stat2.st_mode & S_IXOTH) acl[9] = 'x';
    }
//mx_printstr( "                            acl3   \n" );
    //char* acl = mx_strnew(11);
    /*if (false)
    if ( !mx_check_par(pararr, ' ') ) {

//mx_printstr( "                            acl3-2   \n" );

        acl_t aclt;
        aclt = acl_get_file( filename, ACL_TYPE_ACCESS );
        if ( aclt == NULL ) {
            mx_printstr( "\n  file    " );
            mx_printstr( filename );
            mx_printstr( "  errno2    " );
            mx_printint( errno );
            mx_printstr( "\n" );
            aclt = acl_get_file( filename, ACL_TYPE_DEFAULT );
        }

//mx_printstr( "                            acl3-3   \n" );
        ssize_t sizea = 0;
        char *acltext = acl_to_text( aclt, &sizea );

        if (acltext != NULL) {
//mx_printstr( "                            acl4   \n" );
            mx_printstr( acltext );
            mx_printstr( " " );
            mx_printint( sizea );
            mx_printstr( " " );
            int acl_i = 1;
            for(int i = 0; i < sizea; i++) {
                
//mx_printstr( "                            acl5   \n" );
                bool isacl = false;
                for( ; acltext[i] != '\n'; i++) {

                    if ( isacl || (i >= 6 && i <= 8) || (i >= 17 && i <= 19) || (i >= 28 && i <= 30) ) {
//mx_printstr( "                            acl6   \n" );
                        acl[acl_i] = (char)acltext[i];
                        acl_i++;
                    }
                    else {
                        if (  ) {

                        }
                    }
                }
            }
//mx_printstr( "                            acl7   \n" );
        }
        acl_free( (void*)aclt );
    }*/
    if ( mx_check_par(pararr, ' ') ) {
        //acl[10] = '@';
    }
    return acl;
}


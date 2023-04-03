#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

int test()
{
    if ( true ) { // isatty 

        mx_printstr(" tty(0 - cat): ");
        
        //int fd = open( "file4", O_RDONLY);

        int tty = isatty( 1 );

        mx_printint( tty );

        //mx_printstr(" tty2: ");
        //tty = isatty( 1 );
        //mx_printint( tty );
        mx_printstr(" \n ");
    }
    //#include <types.h>
    //uid_t uid = 0;
    //gid_t gid = 0;
    int uid = 0;
    int gid = 0;
    if ( true ) { // stat 
        mx_printstr(" stat: ");
        
        //int fd = open( "", O_RDONLY);
        struct stat stat1;
        //const char * file1 = ;

        int x = stat( "file4.txt", &stat1 );

        if ( x == 0 ) {
            uid = stat1.st_uid;
            gid = stat1.st_gid;
        }

        mx_printint( x );

        mx_printstr(" file size: ");
        mx_printint( stat1.st_size );
        mx_printstr(" file mod: ");
        mx_printint( stat1.st_mode );
        mx_printstr(" file block: ");
        mx_printint( stat1.st_blocks );

        mx_printstr("\n   file unix mtime:   ");
        mx_printint( stat1.st_mtime );
        //mx_printstr("   file time:   ");
        //mx_printint( time(&stat1.st_mtime) );
        mx_printstr( "   file date:    " ); // mx_get_date
        mx_printstr( mx_get_date( stat1.st_mtime ) ); // mx_get_date
        mx_printstr( "   \n    " ); // mx_get_date

        mx_printstr(" \n ");
        //exit(0);
        //mx_printint( x );
    } // find uid 
    if ( true ) { // pwu 
/*struct passwd {
        char    *pw_name;       // имя пользователя 
        char    *pw_passwd;     // пароль пользователя 
        uid_t   pw_uid;         // id пользователя 
        gid_t   pw_gid;         // id группы 
        char    *pw_gecos;      // настоящее имя 
        char    *pw_dir;        // домашний каталог 
        char    *pw_shell;      // программа-оболочка 
};*/
        mx_printstr(" getpwuid: ");
        mx_printint( uid );

        struct passwd* pwu = getpwuid( uid );

        mx_printstr( " pwu gid: " );
        mx_printint( pwu->pw_gid );
        //gid = pwu->pw_gid;
        mx_printstr( " name: " );
        mx_printstr( pwu->pw_name );
        mx_printstr(" \n ");
    } 
    if ( true ) { // grg 
/*struct group {
        char    *gr_name;        // название группы 
        char    *gr_passwd;      // пароль группы 
        gid_t   gr_gid;          // идентификатор группы 
        char    **gr_mem;        // члены группы 
};*/
        mx_printstr(" getgrgid: ");
        mx_printint( gid );

        struct group* grp = getgrgid( gid );
        mx_printstr( " group: " );
        mx_printstr( grp->gr_name );

        //mx_printint( grp );
        mx_printstr(" \n ");
    } 
    if ( true ) { // acl 
        mx_printstr(" acl_get_file: ");
        //mx_printint( gid );

        acl_t acl;
        acl = acl_get_file( "11file", ACL_TYPE_ACCESS );

        //mx_printstr( " group: " );
        ssize_t sizea = 0;
        char *acltext = acl_to_text( acl, &sizea );

        if (acltext == NULL)
            mx_printstr( " ACL NULL " );
        else {
            mx_printstr( acltext );
        mx_printstr( " " );
        mx_printint( sizea );
        mx_printstr( " " );
        }
        
        //mx_printstr( acltext );
        /*mx_printstr( "\n               ======== acl" );
        mx_printstr( acl );
        mx_printstr( " " );*/
        //mx_printint( sizea );
        

        /*mx_printstr("\n acl_get_file2: ");

        acl = acl_get_file( "file4.txt", ACL_TYPE_ACCESS );
        //mx_printstr( " group: " );
        //mx_printstr( grp->gr_name );
        
        acltext = acl_to_text( acl, &sizea );
        mx_printstr( acltext );
        mx_printstr( " " );
        mx_printint( sizea );
        mx_printstr( " " );*/

        /*mx_printstr( "\n               ======== acl" );
        mx_printint( acl );
        mx_printstr( " " );*/


        acl_free( (void*)acl );

        //mx_printint( acl );

        mx_printstr(" acl end \n ");
        
    } 
    if ( true ) { // opendir readdir closedir 
        mx_printstr("\n o r c dir: ");

        DIR *dir;

        dir = opendir( "./" );
        //mx_printstr( " group: " );
        //mx_printstr( grp->gr_name );
        struct dirent *dirnt;
        dirnt = readdir( dir );
        while (dirnt != NULL) {
            
            mx_printstr( dirnt->d_name );
            mx_printstr( " " );

            dirnt = readdir( dir );
        }
        //mx_printint( sizea );
        //mx_printstr( " " );

        //mx_printint( acl );
        int result = closedir( dir );
        mx_printstr(" close dir: ");
        mx_printint( result );
        mx_printstr(" \n ");
    }
    if ( true ) { // ioctl
        mx_printstr("\n ioctl: ");

        struct winsize ws;
        
        ioctl(0, TIOCGWINSZ, &ws);

        mx_printstr(" rows: ");
        mx_printint( ws.ws_row );
        
        mx_printstr(" cols: ");
        mx_printint( ws.ws_col );
        mx_printstr(" \n ");
    }
    if ( true ) { // listxattr
        mx_printstr("\n listxattr: ");
        
        int sz = 10;
        char* list = mx_strnew(sz);
        
        sz = listxattr("file4.txt", list, sz);

        mx_printstr(" sz: ");
        mx_printint(sz);
        
        mx_printstr(" list: ");
        mx_printstr(list);
        
        mx_printstr(" \n ");
    }

    return 0;
}



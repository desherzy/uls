#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"
#include <errno.h>

char* mx_get_acl(char *filename, char **pararr) {
    struct stat stat1;
    struct stat stat2;
    lstat(filename, &stat1);
    stat(filename, &stat2);

    char* acl = mx_strnew(11);
    for(int i = 0; i < 11; i++) {
        acl[i] = '-';
    }
    acl[10] = ' ';
    int mode = 0;
    if ( S_ISLNK(stat1.st_mode) ) {
        if ( mx_check_par(pararr, 'l') ) {
            acl[0] = 'l';
            mode = 1;
        }
        else {
            if ( S_ISDIR(stat2.st_mode) ) {
                acl[0] = 'd';
                mode = 2;
            }
            else if ( S_ISFIFO(stat2.st_mode) ) {
                acl[0] = 'p';
                mode = 2;
            }
              else if ( S_ISCHR(stat2.st_mode) ) {
                acl[0] = 'c';
                mode = 2;
            }
            else if ( S_ISBLK(stat2.st_mode) ) {
                acl[0] = 'b';
                mode = 2;
            }
            else if ( S_ISSOCK(stat2.st_mode) ) {
                acl[0] = 's';
                mode = 2;
            }
            else if ( S_ISREG(stat2.st_mode) ) {
                acl[0] = '-';
                mode = 2;
            }
            else if ( S_ISWHT(stat2.st_mode)) {
                acl[0] = 'w';
                mode = 2;
            }
        }
    }
    else if ( S_ISDIR(stat1.st_mode) ) {
        acl[0] = 'd';
        mode = 1;
    }
    else if ( S_ISFIFO(stat1.st_mode) ) {
        acl[0] = 'p';
        mode = 1;
    }
    else if ( S_ISCHR(stat1.st_mode) ) {
        acl[0] = 'c';
        mode = 1;
    }
    else if ( S_ISBLK(stat1.st_mode) ) {
        acl[0] = 'b';
        mode = 1;
    }
    else if ( S_ISSOCK(stat1.st_mode) ) {
        acl[0] = 's';
        mode = 1;
    }
    else if ( S_ISREG(stat1.st_mode) ) {
        acl[0] = '-';
        mode = 1;
    }
    else if ( S_ISWHT(stat1.st_mode)) {
        acl[0] = 'w';
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
    if ( true || mx_check_par(pararr, ' ') ) {
        int sz = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
        acl_t aclt = acl_get_file(filename, ACL_TYPE_EXTENDED);

        if (sz > 0) {
            acl[10] = '@';
        }
        else if ((long)aclt > 0) {
            acl[10] = '+';
        }
        acl_free(aclt);
    }
    return acl;
}


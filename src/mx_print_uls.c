#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

int mx_print_uls(char* path, char **pararr, char** namearr, int type) {
    if (mx_check_par(pararr, 'l')) {
        char *fullfilename = NULL;
        int sizelen = 0;
        int linklen = 0;
        int userlen = 0;
        int grouplen = 0;
        struct stat stat1;
        { // find total and size col len
            int total = 0;
            for (int i = 0; namearr[i] != NULL; i++) { 
                { // find full name
                    int s = mx_strlen(path);
                    fullfilename = mx_strnew(s + mx_strlen(namearr[i]) + 1);
                    mx_strcpy(fullfilename, path);
                    if (s != 0) {
                        fullfilename[s] = '/';
                        s++;
                    }
                    int j = 0;
                    for (; namearr[i][j] != '\0' ; s++) {
                        fullfilename[s] = namearr[i][j];
                        j++;
                    }
                }

                lstat(fullfilename, &stat1); 

                total += stat1.st_blocks;

                char * itoa1 = mx_itoa(stat1.st_size);
                int slen = mx_strlen(itoa1);
                if (slen > sizelen) {
                    sizelen = slen;
                } 
                char * itoa2 = mx_itoa(stat1.st_nlink);
                int llen = mx_strlen(itoa2);
                if (llen > linklen) {
                    linklen = llen;
                }
                struct passwd* pwu2 = getpwuid(stat1.st_uid);
                int ulen = mx_strlen(pwu2->pw_name);
                if (ulen > userlen) {
                    userlen = ulen;
                }
                struct group* grp2 = getgrgid(stat1.st_gid);
                int glen = mx_strlen(grp2->gr_name);
                if (glen > grouplen) {
                    grouplen = glen;
                }
                { // clear 
                    mx_strdel(&itoa1);
                    mx_strdel(&itoa2);
                    mx_strdel(&fullfilename);
                }
            }

            if (type == 1) {
                char * itoa1 = mx_itoa(total);

                mx_printstr("total ");
                mx_printstr(itoa1);
                mx_printstr("\n");

                mx_strdel(&itoa1);
            }
        }
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
                for (; namearr[i][j] != '\0' ; s++) {
                    fullfilename[s] = namearr[i][j];
                    j++;
                }
            }

            char *aclstr = mx_get_acl(fullfilename, pararr);
            mx_printstr(aclstr);
            lstat(fullfilename, &stat1); // path + '/' + namearr[i]

            mx_printstr(" ");
            char *nlinkstr = mx_itoa(stat1.st_nlink);
            {
                for (int j = 0; linklen > j + mx_strlen(nlinkstr); j++) { // space
                    mx_printstr(" ");
                }
                mx_printstr(nlinkstr);
            } // print (links?)
            mx_printstr(" ");
            {
                struct passwd* pwu = getpwuid(stat1.st_uid);
                mx_printstr(pwu->pw_name);

                for (int j = 0; userlen > j + mx_strlen(pwu->pw_name); j++) { // space
                    mx_printstr(" ");
                }
            }
            mx_printstr(" ");
            mx_printstr(" ");
            {
                struct group* grp = getgrgid(stat1.st_gid);
                mx_printstr(grp->gr_name);

                for (int j = 0; grouplen > j + mx_strlen(grp->gr_name); j++) { // space
                    mx_printstr(" ");
                }
            }
            mx_printstr(" ");
            mx_printstr(" ");
            char *sizestr = mx_itoa(stat1.st_size);
            {
                for (int j = 0; sizelen > j + mx_strlen( sizestr ); j++) { // space
                    mx_printstr(" ");
                }
                mx_printstr(sizestr);
            } // print size
            mx_printstr(" ");
            char * datestr = mx_get_date(stat1.st_mtime);
            mx_printstr(datestr);
            mx_printstr(" ");
            mx_printstr(namearr[i]);

            size_t link_size = stat1.st_size;
            if (stat1.st_size == 0) {
                link_size = _PC_PATH_MAX;
            }
            char *link_buf = mx_strnew(link_size);
            
            if (readlink(fullfilename, link_buf, link_size) != -1) { //if link
                mx_printstr(" -> ");
                mx_printstr(link_buf);
            }
            mx_printstr("\n");
            { // clear 
                mx_strdel(&aclstr);
                mx_strdel(&nlinkstr);
                mx_strdel(&datestr);
                mx_strdel(&sizestr);
                mx_strdel(&link_buf);
                mx_strdel(&fullfilename);
            }
        }    
    }
    else if (!mx_check_par(pararr, 'l')) {
        if (isatty(1) == 1) {
            mx_print_multicolumn(namearr, pararr);
        }
        else if (isatty(1) == 0) {
            for (int i = 0; namearr[i] != NULL; i++) {
                mx_printstr(namearr[i]);
                mx_printstr("\n");
            }
        }
    }

    return 0;
}


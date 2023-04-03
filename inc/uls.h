#pragma once

// delete beffore pushing
#include <stdio.h>
int test(); // delete

#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <dirent.h>
#include <time.h>

int mx_check_dir( char* dirname, char*** dirarr, char*** filearr, int type ); //
char* mx_get_acl(char *filename, char **pararr); // 

int mx_check_name(char*** namearr, char** pararr); // +?
char* mx_get_date( int unixseconds ); // 
int mx_get_par_arg(char** argv, char*** pararr, char*** argarr); // 

int mx_print_uls( char* path, char **pararr, char** namearr, int type ); // 

int mx_print_multicolumn(char** printarr, char** pararr); 

int mx_sort_arg(char** argarr, char** pararr, char*** dirarr, char*** filearr ); // 
int mx_sort_strarr(char*** strarr);

int mx_ls_cmp(const char *s1, const char *s2);

bool mx_check_par(char** pararr, char parchar); 



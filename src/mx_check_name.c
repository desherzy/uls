#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

// delete all names from readdir which starts with . and sort
int mx_check_name(char*** namearr, char** pararr) {

/*if (namearr == NULL) 
write(1, " na-nul1", 9);
if ( (*namearr) == NULL) 
write(1, " na-nul2", 9);*/
//sleep(5);
//int testi = 0;

    int name_cnt = 0;
    for ( int i = 0; (*namearr)[i] != NULL; i++) {
/*mx_printstr("\n");
mx_printstr((*namearr)[i]);
//write(1, " >43-1", 7);*/
        if ( (*namearr)[i][0] != '.' ) {
//write(1, " + ", 4);

            name_cnt++;
        }
        else if ( mx_check_par(pararr, ' ') &&false) {

            name_cnt++;
        }

        //testi++;
/*write(1, " >43-2", 7);
write(1, " >43-i ", 8);
mx_printint(i);
write(1, " 43-ti ", 8);
mx_printint(testi);*/
    }
//write(1, "\n>43-3", 7);

    char** namearr2 = (char**)malloc( sizeof(char*) * (name_cnt + 1));
    namearr2[name_cnt] = NULL;

/*mx_printstr("\nnamecnt     ");
mx_printint(name_cnt);
mx_printstr("\n        ");*/

    int n = 0;
    for (int j = 0; (*namearr)[j] != NULL; j++) {

//write(1, " >43-4", 7);
        if ( (*namearr)[j][0] != '.' ) {

            namearr2[n] = mx_strdup((*namearr)[j]);
            n++;
        }
        else if ( mx_check_par(pararr, ' ') &&false) {

            namearr2[n] = mx_strdup((*namearr)[j]);
            n++;
        }
//write(1, " >43-7", 7);
    }
    if (!mx_check_par(pararr, ' ') && true) { // sorting 

/*mx_printstr( " \n==============================\n " );
for (int i = 0; namearr2[i] != NULL; i++) {
//write(1, " 021", 5);
    mx_printstr( namearr2[i] );
    mx_printstr( " | " );
}

mx_printstr( " \n==============================\n " );*/

        mx_sort_strarr(&namearr2);
        //mx_sort_strarr(&namearr2);

/*for (int i = 0; namearr2[i] != NULL; i++) {
//write(1, " 021", 5);
    mx_printstr( namearr2[i] );
    mx_printstr( " | " );
}
mx_printstr( "\n ==============================\n " );*/

    }
    else if ( mx_check_par(pararr, ' ') &&false) { // sorting 
        
    }
//write(1, " >43-8", 7);

    // clear namearr
    //mx_del_strarr( &(*namearr) );

//write(1, " >43-82", 8);

/*mx_printstr(" \n ");
mx_print_strarr( (*namearr)," | ");
mx_printstr(" \n ---------------- \n ");
mx_print_strarr( namearr2," | ");*/

    //namearr = &namearr2;
    (*namearr) = namearr2;

//write(1, "  >43-9\n", 9);
    return 0;
}




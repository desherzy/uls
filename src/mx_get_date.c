#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

#include <time.h>
char *mx_get_date(time_t unixseconds) {
    char* ctimestr = ctime( &unixseconds );
    int ctimei = 0;

    char* datestr = mx_strnew(12);
    int datei = 0;
    if (ctimestr != NULL) { // create date string
        for ( ; ctimestr[ctimei] != '\0' && ctimestr[ctimei] != ' '; ) { // skip day of week
            ctimei++;
        }
        ctimei++;
        for ( ; ctimestr[ctimei] != '\0' && ctimestr[ctimei] != ' '; ) { // month 
            datestr[datei] = (char)ctimestr[ctimei];
            datei++;
            ctimei++;
        }
        datestr[datei] = ' ';
        datei++;
        ctimei++;
        for (int i = 0; ctimestr[ctimei] != '\0' && i < 2; i++) { // day 
            datestr[datei] = (char)ctimestr[ctimei];
            datei++;
            ctimei++;
        }
        datestr[datei] = ' ';
        datei++;
        ctimei++;
        int timediff = time(0) - unixseconds;
        if ( timediff < 0 ) {
            timediff *= -1;
        }
        if ( timediff > (6 * 30.44 * 24 * 60 * 60) ) { // timediff > 6 month
            datestr[datei] = ' ';
            datei++;
            ctimei += 9;
            for (; ctimestr[ctimei] != '\0' && ctimestr[ctimei] != '\n'; ) { // year
                datestr[datei] = (char)ctimestr[ctimei];
                datei++;
                ctimei++;
            }
        }
        else { // hour & minute
            for (; ctimestr[ctimei] != '\0' && ctimestr[ctimei] != ':'; ) { // hour
                datestr[datei] = (char)ctimestr[ctimei];
                datei++;
                ctimei++;
            }
            datestr[datei] = ':';
            datei++;
            ctimei++;
            for (; ctimestr[ctimei] != '\0' && ctimestr[ctimei] != ':'; ) { // minute
                datestr[datei] = (char)ctimestr[ctimei];
                datei++;
                ctimei++;
            }
        }
    }

    return datestr; 
}


#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

#include <time.h>
char *mx_get_date( int unixseconds ) { // 01.01.1970 // mounth day hours:minutes 
    //time_t sec;
    //sec = time(NULL);
    int sec = unixseconds; // seconds of current year
    /*mx_printstr("\n<<<<<< sec : ");
    mx_printint( sec );*/
    int year = 0;
    for ( ; sec >= 365 * 24 * 60 * 60; year++) {

        if ( (year + 1970) % 4 == 0 && sec >= 366 * 24 * 60 * 60 ) { // 
            //year++;
            sec -= 366 * 24 * 60 * 60;
        }
        else if ( (year + 1970) % 4 != 0 && sec >= 365 * 24 * 60 * 60 ) {
            //year++;
            sec -= 365 * 24 * 60 * 60;
        }
        else {
            break;
        }
    }
    /*mx_printstr("<<<<<< year sec : ");
    mx_printint( sec );
    mx_printstr("\n     ");*/
    //sec = unixseconds / 365 * 24 * 60 * 60;
    int month = 1;
    bool quit = false;
    for ( ; month < 12; month++ ) {
        quit = true;
        /*mx_printstr("    >msec1:");
        mx_printint( sec );*/
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
                if ( sec >= 31 * 24 * 60 * 60 ) {
                    quit = false;
                    sec -= 31 * 24 * 60 * 60; 
                }
                break;
            case 2: 
                if ((year + 1970) % 4 != 0 && sec >= 28 * 24 * 60 * 60) {
                    quit = false;
                    sec -= 28 * 24 * 60 * 60; 
                }
                else if ((year + 1970) % 4 == 0 && sec >= 29 * 24 * 60 * 60) {
                    quit = false;
                    sec -= 29 * 24 * 60 * 60; 
                }
                break;
            case 4: case 6: case 9: case 11: 
                if ( sec >= 30 * 24 * 60 * 60 ) {
                    quit = false;
                    sec -= 30 * 24 * 60 * 60; 
                }
                break;
        }
        if (quit) {
            //month--;
            break;
        }
        /*mx_printstr(" >msec2:");
        mx_printint( sec );
        mx_printstr(" >mmon:");
        mx_printint( month );*/
    }
    /*mx_printstr("\n<<<<<<<<< month sec: ");
    mx_printint( sec );*/
    //month--;
    int days_in_month = 0;
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            days_in_month = 31;
            break;
        case 2: 
            if ((year + 1970) % 4 != 0) 
                days_in_month = 28;
            else if ((year + 1970) % 4 == 0) 
                days_in_month = 29;
            break;
        case 4: case 6: case 9: case 11: 
            days_in_month = 30;
            break;
    }
    int day = 1;
    for ( ; day <= days_in_month; day++ ) {
        
        if ( sec >= 1 * 24 * 60 * 60 ) {
            sec -= 1 * 24 * 60 * 60;
        }
        else {
            break;
        }
    }
    /*mx_printstr("   days_in_month: ");
    mx_printint( days_in_month );
    mx_printstr("    day: ");
    mx_printint( day );
    mx_printstr("<<<<<<<<< day sec: ");
    mx_printint( sec );
    mx_printstr("\n ");*/
    int hour = 0;
    for ( ; hour <= 23; hour++ ) {
        
        if ( sec >= 1 * 60 * 60 ) {
            sec -= 1 * 60 * 60;
        }
        else {
            break;
        }
    }
    const int gmt = 2;
    {
        hour += gmt;
        if (hour > 23) {
            hour -= 24;
            day += 1;
            if (day > days_in_month) {
                day -= days_in_month;
                month += 1;
                bool m = false;
                /*switch (month) { // 
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
                        days_in_month = 31;
                        break;
                    case 2: 
                        if ((year + 1970) % 4 != 0) 
                            days_in_month = 28;
                        else if ((year + 1970) % 4 == 0) 
                            days_in_month = 29;
                        break;
                    case 4: case 6: case 9: case 11: 
                        days_in_month = 30;
                        break;
                }*/
                if ( m || month > 12 )  {
                    m -= 12;
                    year += 1;
                }
            }
        }
    }
    int minute = 0;
    for ( ; minute <= 59; minute++ ) {
        
        if ( sec >= 1 * 60 ) {
            sec -= 1 * 60;
        }
        else {
            break;
        }
    }
    char* date = NULL;
    { // create final string
        date = mx_strnew(11);
        int date_i = 0;
        char* monthstr = mx_strnew(3);
        //monthstr[0] = '1';
        //monthstr[1] = '2';
        //monthstr[2] = '3';
/*mx_printstr(" d-5 ");
mx_printstr(" year: ");
mx_printint( year + 1970 );
mx_printstr(" month: ");
mx_printint( month );
mx_printstr(" day: ");
mx_printint( day );
mx_printstr(" hour: ");
mx_printint( hour );
mx_printstr(" min: ");
mx_printint( minute );
mx_printstr("   ");*/
        switch (month) {
            case 1: monthstr[0] = 'J';monthstr[1] = 'a';monthstr[2] = 'n'; break;
            case 2: monthstr[0] = 'F';monthstr[1] = 'e';monthstr[2] = 'b'; break;
            case 3: monthstr[0] = 'M';monthstr[1] = 'a';monthstr[2] = 'r'; break;
            case 4: monthstr[0] = 'A';monthstr[1] = 'p';monthstr[2] = 'r'; break;
            case 5: monthstr[0] = 'M';monthstr[1] = 'a';monthstr[2] = 'y'; break;
            case 6: monthstr[0] = 'J';monthstr[1] = 'u';monthstr[2] = 'n'; break;
            case 7: monthstr[0] = 'J';monthstr[1] = 'u';monthstr[2] = 'l'; break;
            case 8: monthstr[0] = 'A';monthstr[1] = 'u';monthstr[2] = 'g'; break;
            case 9: monthstr[0] = 'S';monthstr[1] = 'e';monthstr[2] = 'p'; break;
            case 10: monthstr[0] = 'O';monthstr[1] = 'c';monthstr[2] = 't'; break;
            case 11: monthstr[0] = 'N';monthstr[1] = 'o';monthstr[2] = 'v'; break;
            case 12: monthstr[0] = 'D';monthstr[1] = 'e';monthstr[2] = 'c'; break;
        }
/*mx_printstr("   monthstr:   \"");
mx_printstr(monthstr);
mx_printstr("\"   d-6 ");*/
//exit(-1);
//return 0; 
        char* daystr = mx_itoa(day);
        char* hourstr = mx_itoa(hour);
        char* minutestr = mx_itoa(minute);
        char* yearstr = mx_itoa(year+1970);
        //if ( true ) 
//mx_printstr(" d-62 \n");
        for (int i = 0; monthstr[i] != '\0'; i++) { // month
//mx_printstr(" d-63 ");
            date[date_i] = (char)monthstr[i];
            date_i++;
        }
        date[date_i] = ' ';
        date_i++;
//mx_printstr("\n d-7 ");
        if (mx_strlen(daystr) == 1) {
            date[date_i] = ' ';
            date_i++;
        }
        for (int i = 0; daystr[i] != '\0'; i++) { // day
            date[date_i] = (char)daystr[i];
            date_i++;
        }
        date[date_i] = ' ';
        date_i++;
        int timediff = time(0) - unixseconds;
        if ( timediff < 0 )
            timediff *= -1;
//mx_printstr(" d-8 ");
        if ( timediff > (int)(30.44 * 24 * 60 * 60) ) { //
            if (mx_strlen(hourstr) == 1) {
                date[date_i] = '0';
                date_i++;
            }
            for (int i = 0; hourstr[i] != '\0'; i++) { // 
                date[date_i] = (char)hourstr[i];
                date_i++;
            }
            date[date_i] = ':';
            date_i++;
            if (mx_strlen(minutestr) == 1) {
                date[date_i] = '0';
                date_i++;
            }
            for (int i = 0; minutestr[i] != '\0'; i++) {
                date[date_i] = (char)minutestr[i];
                date_i++;
            }
        }
        else {
            date[date_i] = ' ';
            date_i++;
            for (int i = 0; yearstr[i] != '\0'; i++) {
                date[date_i] = (char)yearstr[i];
                date_i++;
            }
        }
    }
//mx_printstr(" d-9 ");
    return date;
}





#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

#include <time.h>
char *mx_get_date( int unixseconds ) { // 01.01.1970 // mounth day hours:minutes 
    //time_t sec;
    //sec = time(NULL);
    int sec = unixseconds; // seconds of current year
    int year = 0;
    for ( ; sec >= 366 * 24 * 60 * 60; year++ ) {

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
    //sec = unixseconds / 365 * 24 * 60 * 60;
    int month = 1;
    for ( ; month <= 12; month++ ) {
        
        switch (month)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
                if ( true )
                    sec -= 31 * 24 * 60 * 60; 
                break;
            case 2: 
                if ((year + 1970) % 4 != 0) 
                    sec -= 28 * 24 * 60 * 60; 
                else if ((year + 1970) % 4 == 0) 
                    sec -= 29 * 24 * 60 * 60; 
                break;
            case 4: case 6: case 9: case 11: 
                if ( true )
                    sec -= 30 * 24 * 60 * 60; 
                break;
        }
    }
    int days_in_month = 0;
    switch (month)
        {
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
    int hour = 0;
    for ( ; hour <= 23; hour++ ) {
        
        if ( sec >= 1 * 60 * 60 ) {
            sec -= 1 * 60 * 60;
        }
        else {
            break;
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
        
    }
    return date;
}





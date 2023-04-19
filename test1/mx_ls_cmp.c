//#include "../inc/libmx.h"

int mx_ls_cmp(const char *s1, const char *s2) {

    int i = 0;
    for ( ; s1[i] != 0 && s2[i] != 0 ; i++) {
        
        int char1 = s1[i];
        int char2 = s2[i];
        if (char1 >= 48 && char1 <= 57) {

        }
        if ((char2 >= 65 && char2 <= 90) && (char1 >= 65 && char1 <= 90)
            && (char1 >= 97 && char1 <= 122) && (char2 >= 97 && char2 <= 122)
            && (char1 >= 48 && char1 <= 57) && (char2 >= 48 && char2 <= 57)) {

                /*if (false) {

                }*/
        }

        if (char1 < char2) {

            return char1 - char2;
        }
        else if (char1 > char2) {

            return char1 - char2;
        }
    }
    if (s1[i] == 0 && s2[i] != 0) {
        return -1;
    }
    else if (s2[i] == 0 && s1[i] != 0) {
        return 1;
    }
    return 0;
}
// sorts only a-z A-Z 0-9 
// others skip 
// file10 -> file100
// _2file -> 2file
// 1 -> a
// A -> a -> B 
// 
/*void mx_print_alphabet(void) {
    for (int i = 65; i <= 90; i++) {
        int x = i;
        if (x % 2 == 0) {
            x += 32;
        }
        mx_printchar(x);
    }
    mx_printchar(10);
}*/




#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"

bool mx_check_par(char** pararr, char parchar) {
    int i = 0;
    if (pararr != NULL) {
        for (; pararr[i] != NULL; i++) {
            if (pararr[i][0] == parchar && pararr[i][0] != '\0') {
                return true;
            }
        }
    }
    return false;
}



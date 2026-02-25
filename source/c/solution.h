#define SOLUTION_H
#ifdef SOLUTION_H

#include <stdlib.h>

char* intToRoman(int num) {
    char *ans = (char*) malloc(2 * sizeof(char));
    ans[0] = '0';
    ans[1] = '\0';

    return ans;
}

#endif
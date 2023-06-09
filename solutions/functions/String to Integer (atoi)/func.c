#include <limits.h>

int myAtoi(char * s) {
    while (*s == ' ') {
        s++;
    }
    if (!*s) {
        return 0;
    }
    int negativeFlag = 0;
    if (*s == '+') {
        s++;
    } else if (*s == '-') {
        negativeFlag = 1;
        s++;
    }
    int res = 0, quotient = INT_MAX / 10, remainder = INT_MAX % 10;
    while (*s >= '0' && *s <= '9') {
        int num = *s++ - '0';
        if (!negativeFlag && (res > quotient || (res == quotient && num >= remainder))) {
            return INT_MAX;
        }
        if (negativeFlag && (res > quotient || (res == quotient && num >= remainder + 1))) {
            return INT_MIN;
        }
        res = res * 10 + num;
    }
    return negativeFlag ? -res : res;
}
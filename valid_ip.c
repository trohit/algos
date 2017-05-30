/*
 * Program to check for a valid IP
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#define MAXDIGITS 3
int digits;
int sumdigits;
int dots;
int buf[3];
typedef enum _type {
    other,
    digit,
    dot
} type;

bool is_digit(char ch)
{
    if (ch < '0' || ch > '9') {
        return false;
    }
    return true;
}

type classify(char ch)
{
    type t = other;
    if (is_digit(ch)) {
        //printf("\n%c is a digit", ch);
        t = digit;
    } else if (ch == '.') {
        //printf("\n%c is a dot", ch);
        t = dot;
    }
    return t;
}

bool consume(char ch)
{
    bool is_valid = true;
    type t = classify(ch);
    switch (t) {
        case digit:
            sumdigits = (sumdigits * 10) +  (ch - '0');
            if (sumdigits < 1 || sumdigits > 254) {
                is_valid = false;
                break;
            }
            digits++;
            if (digits > MAXDIGITS) {
                //printf("too many digits");
                is_valid = false;
            }
            break;
        case dot:
            //printf("\n sumdigits:[%u]", sumdigits);
            dots++;
            //printf("\n moving to dot %u", dots);
            digits = 0;
            sumdigits = 0;
            if (dots > 3) {
                printf("too many dots");
                is_valid = false;
            }
            break;
        default:
            //printf("invalid char %c", ch);
            is_valid = false;
            break;
    }
    return is_valid;
}


int main()
{
    char ip[18];
    bool res;
    int i = 0;
    printf("enter IP:");
    scanf("%s", ip);
    //printf("you entered [%s]", ip);
    while (i < strlen(ip)) {
        res = consume(ip[i]);
        if (res == false) {
            printf("Invalid IP");
            return 0;
        }
        i++;
    }
    printf("valid IP");
    return 0;
}

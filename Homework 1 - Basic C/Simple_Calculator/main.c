#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "define.h"

int main()
{
    opening();

    // write your code here
    float a, b, res;
    char c;
    printf("Input: ");
    scanf("%f %c %f", &a, &c, &b);

    switch (c)
    {
    case '+':
        res = a + b;
        printf("Output: %g", res);
        break;

    case '-':
        res = a - b;
        printf("Output: %g", res);
        break;

    case '*':
        res = a * b;
        printf("Output: %g", res);
        break;

    case '/':
        res = a / b;
        printf("Output %g", res);
        break;

    default:
        printf("n Invalid entry");
    }

    //end of your code

    return 0;
}

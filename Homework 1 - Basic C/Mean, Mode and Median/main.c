#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    printf("Enter a number to append to the number set. Enter \"/\" to stop appending.\n");

    int n, count;
    float tot = 0;
    float mean;
    count = 0;
    int num[20] = {};

    for (int i = 0; i < 19; i++)
    {
        // scanf("%d", &n);
        if (!scanf("%d", &n))
            break;
        num[i] = n;
        count++;
    }
    num[count] = '\0';

    int size = count;
    /*
    printf("%d", size);
    for (int i = 0; i < size; i++)
        printf("%d \n", num[i]);
    */

    //mean
    for (int j = 0; j < size; j++)
    {
        tot = tot + num[j];
    }
    mean = tot / size;
    printf("Mean = %g \n", mean);

    //median
    float median = 0;
    float mid = 0;
    if (size % 2 == 0)
    {
        int temp = (size / 2) - 1;
        for (int i = 0; i < size; i++)
        {
            if (temp == i || (temp + 1) == i)
            {
                mid = mid + num[i];
            }
        }
        mid = mid / 2;
        printf("Median = %g \n", mid);
    }
    else
    {
        int temp = (size / 2);
        for (int i = 0; i < size; i++)
        {
            if (temp == i)
            {
                int mid = num[i];
                printf("Median = %g \n", mid);
            }
        }
    }

    // Mode
    int tmp, maxCount, modeValue;
    int tally[20] = {};
    // getting ordered array
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (num[j] > num[j + 1])
            {
                tmp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = tmp;
            }
        }
    }
    /*
    for (int x = 1; x <= size; x++)
        printf("%d ", num[x]);
    */
    for (int i = 1; i <= size; i++)
    {
        for (int z = i + 1; z <= size; z++)
        {
            if (num[i] == num[z])
            {
                tally[i]++;
            }
        }
    }

    maxCount = 0;
    modeValue = 0;
    for (int i = 1; i <= size; i++)
    {
        if (tally[i] > maxCount)
        {
            maxCount = tally[i];
            modeValue = num[i];
        }
    }
    printf("Mode = %d \n", modeValue);

    return 0;
}
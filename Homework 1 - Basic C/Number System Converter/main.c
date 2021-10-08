#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    // write your code here
    printf("Welcome to Number System Converter\n");

    int number, cnt, i, rem, hexNumber;
    int size = 0;
    char HexNum[32] = {0};
    int system, system1;
    int bin[32];
    char hex[32];
    bool state = true;

    printf("Please enter a set of number: ");
    scanf("%s", HexNum);
    printf("Please enter the current number system: ");
    scanf("%d", &system);
    while (HexNum[size])
    {
        size++;
    }
    if (system == 10)
    {
        for (int i = 0; i < size; i++)
        {
            if (HexNum[i] >= 65)
            {
                printf("Error! That set of number is not a decimal number.");
                state = false;
                break;
            }
        }
    }
    else if (system == 2)
    {
        for (int i = 0; i < size; i++)
        {
            if (HexNum[i] != 49 || HexNum[i] != 48)
            {
                printf("Error! That set of number is not a binary number.");
                state = false;
                break;
            }
        }
    }
    if (state)
    {
        printf("Please enter the number system you want the set of number be converted to: ");
        scanf("%d", &system1);
    }

    // case 1 (10 to 2) done
    if (system == 10 && system1 == 2)
    {
        cnt = 0;
        number = atoi(HexNum);
        while (number > 0)
        {
            bin[cnt] = number % 2;
            number = number / 2;
            cnt++;
        }

        /*print value in reverse order*/
        printf("Output: ");
        for (i = (cnt - 1); i >= 0; i--)
            printf("%d", bin[i]);
    }
    // case 2 (10 to 16) done
    else if (system == 10 && system1 == 16)
    {
        cnt = 0; /*initialize index to zero*/
        number = atoi(HexNum);
        while (number > 0)
        {
            switch (number % 16)
            {
            case 10:
                hex[cnt] = 'A';
                break;
            case 11:
                hex[cnt] = 'B';
                break;
            case 12:
                hex[cnt] = 'C';
                break;
            case 13:
                hex[cnt] = 'D';
                break;
            case 14:
                hex[cnt] = 'E';
                break;
            case 15:
                hex[cnt] = 'F';
                break;
            default:
                hex[cnt] = (number % 16) + 0x30; /*converted into char value*/
            }
            number = number / 16;
            cnt++;
        }

        /*print value in reverse order*/
        printf("Output: ");
        for (i = (cnt - 1); i >= 0; i--)
            printf("%c", hex[i]);
    }
    // case 3 (2 to 10) unfinished!
    else if (system == 2 && system1 == 10)
    {
        number = atoi(HexNum);
        int base = 1;
        int dec_value = 0;

        while (number)
        {
            int last_digit = number % 10;
            number = number / 10;
            dec_value += last_digit * base;
            base = base * 2;
        }

        printf("Output: %d", dec_value);
    }
    // case 4 (2 to 16) done
    else if (system == 2 && system1 == 16)
    {
        number = atoi(HexNum);
        while (number != 0)
        {
            rem = number % 10;
            hexNumber = hexNumber + rem * i;

            i = i * 2;
            number = number / 10;
        }

        printf("Output: %X", hexNumber);
    }
    // case 5 (16 to 2) done
    else if (system == 16 && system1 == 2)
    {
        int x = 0;

        while (HexNum[x])
        {
            switch (HexNum[x])
            {
            case '0':
                printf("0000");
                break;

            case '1':
                printf("0001");
                break;

            case '2':
                printf("0010");
                break;

            case '3':
                printf("0011");
                break;

            case '4':
                printf("0100");
                break;

            case '5':
                printf("0101");
                break;

            case '6':
                printf("0110");
                break;

            case '7':
                printf("0111");
                break;

            case '8':
                printf("1000");
                break;

            case '9':
                printf("1001");
                break;

            case 'a':
            case 'A':
                printf("1010");
                break;

            case 'b':
            case 'B':
                printf("1011");
                break;

            case 'c':
            case 'C':
                printf("1100");
                break;

            case 'd':
            case 'D':
                printf("1101");
                break;

            case 'e':
            case 'E':
                printf("1110");
                break;

            case 'f':
            case 'F':
                printf("1111");
                break;

            default:
                printf("\nInvalid hexa digit: %c", HexNum[x]);
                return 0;
            }
            x++;
        }
    }
    //case 6 (16 to 10)
    else if (system == 16 && system1 == 10)
    {

        // Initializing base value to 1, i.e 16^0
        int base1 = 1;

        int dec_val = 0;
        int z = 0;
        // Extracting characters as digits from last
        // character
        while (HexNum[z])
        {
            // if character lies in '0'-'9', converting
            // it to integral 0-9 by subtracting 48 from
            // ASCII value
            if (HexNum[z] >= '0' && HexNum[z] <= '9')
            {
                dec_val += (HexNum[z] - 48) * base1;

                // incrementing base by power
                base1 = base1 * 16;
            }

            // if character lies in 'A'-'F' , converting
            // it to integral 10 - 15 by subtracting 55
            // from ASCII value
            else if (HexNum[z] >= 'A' && HexNum[z] <= 'F')
            {
                dec_val += (HexNum[z] - 55) * base1;

                // incrementing base by power
                base1 = base1 * 16;
            }
            z++;
        }
        printf("Output: %d ", dec_val);
    }
    //end of your code

    return 0;
}

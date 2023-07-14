#include <stdio.h>
#include "function.h"

int main()
{
    int i, d, day1, month1, year1, a;
    date(&day1, &month1, &year1);
    openexistingfile();
whilestart:
    while (1)
    {
        optionprinting();
        a = scanf("%d", &i);
        getchar();
        if (a != 1)
        {
            printf("Please enter number only\n");
            goto whilestart;
        }
        printf("\n\n");
        switch (i)
        {
        case 1:
            readfile();
            break;
        case 2:
            transfer();break;
        case 3:
            NewBankaccount(day1, month1, year1);
            break;
        case 4:
            MyBalance(year1,month1,day1);break;
        case 5:
            exit(1);
        default:
            printf("Please choose the correct option\n");
            break;
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

/* Converts a month's numeric representation to its literal name. */
int main()
{
    int month;
    bool invalid_input = false;

    do{

        if(invalid_input){
            printf("Invalid Month!\n");
        }

        printf("Enter month number: ");
        scanf("%d",&month);

        invalid_input = true;

    }while( month < 1 || month > 12);

    switch (month)
    {
    case 1:
        printf("Month number #%d: January", month);
        break;

    case 2:
        printf("Month number #%d: February", month);
        break;

    case 3:
        printf("Month number #%d: March", month);
        break;

    case 4:
        printf("Month number #%d: April", month);
        break;

    case 5:
        printf("Month number #%d: May", month);
        break;

    case 6:
        printf("Month number #%d: June", month);
        break;

    case 7:
        printf("Month number #%d: July", month);
        break;

    case 8:
        printf("Month number #%d: August", month);
        break;

    case 9:
        printf("Month number #%d: September", month);
        break;

    case 10:
        printf("Month number #%d: October", month);
        break;

    case 11:
        printf("Month number #%d: November", month);
        break;

    case 12:
        printf("Month number #%d: December", month);
        break;

    default:
        printf("Hmm...Something's not right.");
        break;
    }

    printf("\n");

    return 0;
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    /* Verify if card number size is valid */
    char *numberCard;
    int length;
    numberCard = get_string("Number: ");
    length = strlen(numberCard);

    bool invalidCard = false;

    /* Select check digits */

    char numberCardArray[length];        /* Create a list that will store the card number */
    strcpy(numberCardArray, numberCard); /* Transfers the card number as a string to a list */
    int verifyNumber[2];                 /* To verify the card you only need two numbers */
    char *cardNetwork = NULL;            /* The card network starts empty*/

    /* Assigning card verification number*/
    for (int i = 0; i < 2; i++)
    {
        verifyNumber[i] = numberCardArray[i];
    }
    /* Assigning the network card */
    if (verifyNumber[0] == '4')
    {
        if (length == 13 || length == 16)
        {
            cardNetwork = "VISA";
        }
    }
    else if (verifyNumber[0] == '3')
    {
        if (verifyNumber[1] == '4' || verifyNumber[1] == '7')
        {
            if (length == 15)
            {
                cardNetwork = "AMEX";
            }
        }
    }
    else if (verifyNumber[0] == '5')
    {
        if (verifyNumber[1] >= '1' && verifyNumber[1] <= '5')
        {
            if (length == 16)
            {
                cardNetwork = "MASTERCARD";
            }
        }
    }
    else
    {
        invalidCard = true;
    }

    /* separate numbers and group them into lists */
    int size = length / 2;
    char groupA[size];          /* Counting numbers from the penultimate */
    char groupB[length - size]; /* Remaining numbers */
    int p;

    /* Separating the numbers into group A */
    p = length - 2;
    for (int i = 0; i < size; i++)
    {
        groupA[i] = numberCardArray[p];
        p -= 2;
    }

    /* Separating the numbers into group B */
    p = length - 1;
    for (int i = 0; i < length - size; i++)
    {
        groupB[i] = numberCardArray[p];
        p -= 2;
    }

    /* Multiplying the numbers in group A by 2 */
    int listNumbers[size];
    for (int i = 0; i < size; i++)
    {
        listNumbers[i] = (groupA[i] - '0') * 2;
    }

    /* Creating a new list and assigning the group A numerals separately */
    char newList[size];
    for (int i = 0; i < size; i++)
    {
        if (listNumbers[i] >= 10)
        {
            int n1 = listNumbers[i] / 10;
            int n2 = listNumbers[i] % 10;
            newList[i] = n1 + n2;
        }
        else
        {
            newList[i] = listNumbers[i];
        }
    }
    /* Adding the digits of the new list */
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        int num = newList[i];
        sum += num;
    }

    /* Adding the sum with the numbers in group B */
    for (int i = 0; i < length - size; i++)
    {
        int num = groupB[i] - '0';
        sum += num;
    }

    /* Validating the sum of the card digit */
    if ((sum % 10) != 0)
    {
        invalidCard = true;
    }

    /* Show the result */
    if (invalidCard == true || cardNetwork == NULL)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("%s\n", cardNetwork);
    }
}

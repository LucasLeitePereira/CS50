#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);
char rotate(char c, int k);

int main(int argc, string argv[])
{
    /* Checking the Key */
    if (argc == 2)
    {
        bool valid = only_digits(argv[1]);
        if (valid == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    /* Using the Key */
    int key = atoi(argv[1]);

    /* plainText */
    string plainText = get_string("plaintext:  ");
    int lengthText = strlen(plainText);

    char cipherText[lengthText + 1];
    cipherText[lengthText] = '\0';
    for (int i = 0; i < lengthText; i++)
    {
        cipherText[i] = rotate(plainText[i], key);
    }
    printf("ciphertext: %s\n", cipherText);

    return 0;
}

bool only_digits(string s)
{
    int length = strlen(s);
    bool itsValid = false;
    for (int i = 0; i < length; i++)
    {
        if (isdigit(s[i]))
        {
            itsValid = true;
        }
        else
        {
            itsValid = false;
        }
    }
    return itsValid;
}

char rotate(char c, int k)
{
    char letter = '\0';

    if (isalpha(c))
    {
        if (isupper(c))
        {
            int current_letter = (int) c;
            int letter_behind = current_letter - 65;
            int letter_in_front = 90 - current_letter;
            if (k > 0)
            {
                while (k > letter_in_front)
                {
                    k -= 26;
                }
                letter = c + k;
            }

            else if (k < 0)
            {
                while (k < 0)
                {
                    k = k + 26;
                }
                while (k > letter_in_front)
                {
                    k -= 26;
                }
                letter = c + k;
            }
            else
            {
                letter = c;
            }
        }
        else if (islower(c))
        {
            int current_letter = (int) c;
            int letter_behind = current_letter - 97;
            int letter_in_front = 122 - current_letter;
            if (k > 0)
            {
                while (k > letter_in_front)
                {
                    k -= 26;
                }
                letter = c + k;
            }

            else if (k < 0)
            {
                while (k < 0)
                {
                    k = k + 26;
                }
                while (k > letter_in_front)
                {
                    k -= 26;
                }
                letter = c + k;
            }
            else
            {
                letter = c;
            }
        }
    }
    else
    {
        letter = c;
    }
    return letter;
}

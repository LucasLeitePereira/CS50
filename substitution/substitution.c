#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_string(string s);
char rotate(char c, char a[]);
bool verify_duplicate(string s);

int main(int argc, string argv[])
{
    /* Checking the Key */
    int length_argv;
    if (argc == 2)
    {
        length_argv = strlen(argv[1]);
        bool valid = only_string(argv[1]);
        bool duplicate = verify_duplicate(argv[1]);
        if (valid == false)
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        else if (length_argv != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else if (duplicate)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char new_alphabet[length_argv];
    new_alphabet[length_argv] = '\0';

    for (int i = 0; i < length_argv; i++)
    {
        new_alphabet[i] = argv[1][i];
    }

    /* plainText */
    string plainText = get_string("plaintext:  ");
    int lengthText = strlen(plainText);

    char cipherText[lengthText + 1];
    cipherText[lengthText] = '\0';
    for (int i = 0; i < lengthText; i++)
    {
        cipherText[i] = rotate(plainText[i], new_alphabet);
    }
    printf("ciphertext: %s\n", cipherText);

    return 0;
}

bool only_string(string s)
{
    int length = strlen(s);
    bool itsValid = false;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(s[i]))
        {
            itsValid = true;
        }
        else
        {
            itsValid = false;
            break;
        }
    }
    return itsValid;
}

bool verify_duplicate(string s)
{
    bool there_duplicate = false;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        char letterOne = s[i];

        for (int j = 0; j < length; j++)
        {
            char letterTwo = s[j];
            if (i != j)
            {
                if (letterOne == letterTwo)
                {
                    there_duplicate = true;
                }
            }
        }
    }
    return there_duplicate;
}

char rotate(char c, char a[])
{
    char letter_alphabet = toupper(c);
    int postion_letter_alphabet = (int) letter_alphabet - 65;
    char letter = a[postion_letter_alphabet]; /* Gets the position of the letter equivalent to the
                                                 new alphabet */

    if (isalpha(c))
    {
        if (isupper(c))
        {
            letter = toupper(letter);
        }
        else if (islower(c))
        {
            letter = tolower(letter);
        }
    }
    else
    {
        letter = c;
    }

    return letter;
}

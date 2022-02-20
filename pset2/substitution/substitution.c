#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_alpha(string key);
bool check_char(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");                          // if input more or less than one argement
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");                    // if input more or less than 26 char
        return 1;
    }
    if (is_alpha(argv[1]) == false)
    {
        printf("Must be all alphabetic character\n");                   //if input non-alphabitical charactars
        return 1;
    }
    if (check_char(argv[1]) == false)
    {
        printf("Must Use diffrent characters\n");                       // if input the same char twice
        return 1;
    }
    string ptxt = get_string("plaintext:  ");
    for (int n = 0; n < strlen(ptxt); n++)                              // doing the math and bla bla bla
    {
        if (ptxt[n] >= 65 && ptxt[n] <= 90)
        {
            int cap = ptxt[n] - 65;
            ptxt[n] = argv[1][cap];
            ptxt[n] = toupper(ptxt[n]);
        }
        else if (ptxt[n] >= 97 && ptxt[n] <= 122)
        {
            int sml = ptxt[n] - 97;
            ptxt[n] = argv[1][sml];
            ptxt[n] = tolower(ptxt[n]);
        }
        else
        {
            ptxt[n] = ptxt[n];
        }

    }
    printf("ciphertext: %s\n", ptxt);
}


bool is_alpha(string key)                                               // checks if all alpha
{
    bool check;
    for (int n = 0; key[n] != '\0'; n++)
    {
        if (key[n] >= 65 && key[n] <= 90)
        {
            check = true;
        }
        else if (key[n] >= 97 && key[n] <= 122)
        {
            check = true;
        }
        else
        {
            check = false;
        }
    }
    return check;
}

bool check_char(string key)                                         // checks if the char is typed twice
{
    bool check = true;
    for (int n = 0; key[n] != '\0'; n++)
    {
        for (int i = 1 + n; key[i] != '\0'; i++)
        {
            if (key[n] == key[i] || key[n] == (key[i] - 32) || key[n] == (key[i] + 32))
            {
                check = false;
            }
        }

    }
    return check;
}
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_digit(string key);

int main(int argc, string argv[])
{
    if (argc != 2)                                  // if the user typed more or less than 2 argements
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (is_digit(argv[1]) ==
        false)                 // cheks if the user typed other things than number with a function i wrote "yes i'm broud of that function"
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    string ptxt = get_string("plaintext:  ");       // prmopt the user fot the plainText
    int key = atoi(argv[1]);                        // convert from string to integer
    //printf("ciphertext: ");
    for (int n = 0; n < strlen(ptxt); n++)          // doing the math and bla bla bla
    {
        if (ptxt[n] >= 65 && ptxt[n] <= 90)
        {
            ptxt[n] = (((ptxt[n] - 'A') + key) % 26) + 'A';
            //printf("%c",ptxt[n]);
        }
        else if (ptxt[n] >= 79 && ptxt[n] <= 122)
        {
            ptxt[n] = ((((ptxt[n] - 'a')) + key) % 26) + 'a';
            //printf("%c",ptxt[n]);
        }
        else
        {
            //printf("%c",ptxt[n]);
        }
        
    }
    printf("ciphertext: %s\n", ptxt); // i added coment in the condition u can choose one of them
}


bool is_digit(string key)
{
    bool check;
    for (int n = 0; key[n] != '\0'; n++)
    {
        if (key[n] < 48 || key[n] > 57)
        {
            check  = false;
        }
        else
        {
            check = true;
        }
    }
    return check;
}

#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");     // prompt the user
    //int txtlen = strlen(text);    // count all symbols in the text
    int letterslen = count_letters(text);   // count the number of letters only with a function i wrote
    int wordslen = count_words(text);   // count the number of word with a function
    int sentenceslen = count_sentences(text);   // count the number of sentences with function i wrote
    float l = ((float)letterslen / wordslen) * 100;    //avrege number of  letters
    float s = ((float)sentenceslen / wordslen) * 100;  // avrege number of sentences
    int grade = round((0.0588 * l) - (0.296 * s) - 15.8);
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }


}

int count_letters(string text)
{
    int letterslen = 0;
    for (int n = 0; text[n] != '\0'; n++)
    {
        if (text[n] <= 90 && text[n] >= 65)
        {
            letterslen++;
        }
        if (text[n] <= 122 && text[n] >= 97)
        {
            letterslen++;
        }
    }
    return letterslen;
}

int count_words(string text)
{
    int wordslen = 1;
    for (int n = 0; text[n] != '\0'; n++)
    {
        if (text[n] == 32) // count 1 word if space is found
        {
            wordslen++;
            if (text[n + 1] == 32)
            {
                wordslen--;
            }
        }
    }
    return wordslen;
}

int count_sentences(string text)
{
    int sentenceslen = 0;
    for (int n = 0; text[n] != '\0'; n++)
    {
        if (text[n] == 33) // count 1 if Exclamation mark is found
        {
            sentenceslen++;
        }
        if (text[n] == 46) // count 1 if dot or full stop is found
        {
            sentenceslen++;
        }
        if (text[n] == 63) // count 1 if Question mark is found
        {
            sentenceslen++;
        }
    }
    return sentenceslen;
}



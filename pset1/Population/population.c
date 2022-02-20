#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    int end;
    //Prompt for start size
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    //Prompt for end size
    do 
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // Calculate number of years until we reach threshold
    int n = 0;
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        n++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", n);
}
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == 2)
            {
                break;
            }
            printf("%i", j);
        }
    }
}
  for (int i = 0; i < pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
        for(int j = 0; j < pair_count; j++)
        {
            if (locked[pairs[j].winner][pairs[j].loser] && pairs[i].winner == pairs[j].loser)
            {
                    locked[pairs[i].winner][pairs[i].loser] = false;
            }

        }
    }
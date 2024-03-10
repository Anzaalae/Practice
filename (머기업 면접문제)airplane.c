#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int seat[100] = {0};
    int rand_seat;
    int count = 0;
    int i, j, k;

    srand(time(NULL));

    for(i = 0; i < 10000; i++)
    {
        rand_seat = rand()%100;
        seat[rand_seat] = 1;

        for(j = 1; j < 99; j++)
        {
            if(seat[j] == 0) seat[j] = 1;
            else
            {
                while(seat[rand_seat] == 1)
                {
                    rand_seat = rand()%100;
                }

                seat[rand_seat] = 1;
            }
        }

        if(seat[99] == 0)
        count++;

        for(k = 0; k< 100; k++)
        {seat[k] = 0;}
    }

    printf("10000, %d", count);

}
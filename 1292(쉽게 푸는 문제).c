#include <stdio.h>

int main()
{
    int add1, add2;
    scanf("%d %d", &add1, &add2);

    int count= 0;
    int total= 0;

    for(int i= 1;; i++)
    {
        if(count== add2) break;
        for(int j= 1; j<= i; j++)
        {
            if(count== add2) break;
            total+= i;
            count++;
        }
    }

    count= 0;

    for(int i= 1;; i++)
    {
        if(count== add1- 1) break;
        for(int j= 1; j<= i; j++)
        {
            if(count== add1- 1) break;
            total-= i;
            count++;
        }
    }

    printf("%d", total);
}
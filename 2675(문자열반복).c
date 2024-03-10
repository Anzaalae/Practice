#include <stdio.h>

int main()
{
    char a[2][1000];
    char cal;
    scanf("%s\n%c\n%s", &a[0], &cal, &a[1]);

    int check[2] = {0, 0};

    for(int i = 0; i < 2; i++) while(a[i][check[i]] == '1' || a[i][check[i]] == '0') check[i]++;

    if(cal == '*')
    {
        if(a[0][0] == '0' || a[1][0] == '0')
        {
            printf("0");
        }
        else
        {
            char output[2000];

            output[0] = '1';
            check[0] += check[1] -2;
            for(; check[0] >0; check[0]--) output[check[0]] = '0';
            printf("%s", output);
        }
    }
    else if(cal == '+')
    {
        if(a[0][0] == '0')
        {
            printf("%s", a[1]);
        }
        else if(a[1][0] == '0')
        {
            printf("%s", a[0]);
        }
        else if(check[0] == check[1])
        {
            a[0][0] = '2';
            printf("%s", a[0]);
        }
        else if(check[0] > check[1])
        {
            a[0][check[0] - check[1]] = '1';
            printf("%s", a[0]);
        }
        else if(check[0] < check[1])
        {
            a[1][check[1] - check[0]] = '1';
            printf("%s", a[1]);
        }
    }
}
#include <stdio.h>

int main()
{
    unsigned long long int num;
    scanf("%llu", &num);

    unsigned long long int total= 0;
    unsigned long long int add= 0;

    for(int i= 1; i< num; i++)
    {
        add= num* (num- i)+ (num- i);
        total+= add;
    }

    printf("%llu", total);
}

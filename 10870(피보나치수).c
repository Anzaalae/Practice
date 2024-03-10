#include <stdio.h>

int main()
{
    int a = 0, b = 1;
    int temp;
    int count;

    scanf("%d", &count);

    if(count== 0)
    {
        printf("0");
        return 0;
    }
    else if(count== 1)
    {
        printf("1");
        return 0;
    }

    for(int i= 0; i< count- 1; i++)
    {
        temp= a+ b;
        a= b;
        b= temp;
    }

    printf("%d", b);
}
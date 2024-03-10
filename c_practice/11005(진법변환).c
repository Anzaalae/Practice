#include <stdio.h>

int main()
{
    int input, cal;
    scanf("%d %d", &input, &cal);

    char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int cal_num = input;
    int i = 0;

    int output[30];
    
    output[0] = input % cal;

    while(cal_num>=cal)
    {
        i++;
        cal_num /= cal;
        output[i] = cal_num % cal;
    }

    output[i] = cal_num;

    for(; i >= 0; i--)
    {
        if(output[i] < 10)
        printf("%d", output[i]);
        else
        printf("%c", alpha[output[i]-10]);
    }
    
}

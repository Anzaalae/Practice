#include <stdio.h>

int main()
{
    int count;
    scanf("%d", &count);

    float input[count];
    char cal[count][6];

    for(int i =0; i <count; i++)
    {
        scanf("%f %[^\n]", &input[i], &cal[i]);

        for(int j = 0; j < 5; j+=2)
        {
            if(cal[i][j] == '@') input[i] *=3.0;
            else if(cal[i][j] == '%') input[i] +=5.0;
            else if(cal[i][j] == '#') input[i] -=7.0;
            else continue;
        }
    }

    for(int k=0; k<count; k++)
    printf("%.2f\n", input[k]);

}
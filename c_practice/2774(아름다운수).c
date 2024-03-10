#include <stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    
    char test[num][11]= {'\0'};
    int result[num];
    int check[]= {0,0,0,0,0,0,0,0,0,0};
    int count= 0;

    for(int i= 0; i< num; i++)
    {
        scanf("%s", &test[i]);
        result[i]= 0;
        while(test[i][count] != '\0') // 각 자릿수 숫자 카운트
        {
            check[test[i][count]-48]++;
            count++;
        }
        for(int j= 0; j< 10; j++) if(check[j]> 0) result[i]++; // 각 자릿수 숫자가 한번이라도 나오면 카운트

        for(int k= 0; k< 10; k++) check[k] = 0;
        count= 0;
    }

    for(int i= 0; i< num; i++) printf("%d\n", result[i]);
}

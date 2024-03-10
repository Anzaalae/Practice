#include <stdio.h>
#include <math.h>

int main()
{
    int num;
    int check =0;

    scanf("%d", &num);

    if(num >= 1 && num <=4)
    {
        printf("4");
        return 0;
    }

    while(check == 0)
    {
        for(int i = 2; i <= ceil(sqrt(num)); i++) if(num% i== 0) check =1;
        // 2부터 루트(검사하는 숫자) 이후로 약수가 없음
        num++;
    }

    printf("%d", num - 1);
}
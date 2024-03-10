#include <stdio.h>

int main()
{
    int scale;

    scanf("%d", &scale);

    for(int i= 0; i< scale; i++) // 상단 별 그리기
    {
        for(int j=0; j < i; j++) printf(" "); // 띄어쓰기 입력 부분
        for(int k=0; k < (2* (scale-i)) - 1; k++) printf("*"); // 별 입력 부분
        printf(" \n");
    }
    for(int i = 2; i<= scale; i++) // 하단 별 그리기
    {
        for(int j=scale-i; j>0; j--) printf(" ");
        for(int k=0; k< i*2-1; k++) printf("*");
        printf(" \n");
    }
}
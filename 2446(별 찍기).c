#include <stdio.h>

int main()
{
    int scale;

    scanf("%d", &scale);

    for(int i= 0; i< scale; i++) // ��� �� �׸���
    {
        for(int j=0; j < i; j++) printf(" "); // ���� �Է� �κ�
        for(int k=0; k < (2* (scale-i)) - 1; k++) printf("*"); // �� �Է� �κ�
        printf(" \n");
    }
    for(int i = 2; i<= scale; i++) // �ϴ� �� �׸���
    {
        for(int j=scale-i; j>0; j--) printf(" ");
        for(int k=0; k< i*2-1; k++) printf("*");
        printf(" \n");
    }
}
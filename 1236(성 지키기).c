#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int i;
    int count[2]= {0, 0};

    char field[m][n+ 1];
    int check1[m]; for(i=0; i< m; i++) check1[i]= 0;
    int check2[n]; for(i=0; i< n; i++) check2[i]= 0;

    for(i= 0;i< m; i++) scanf("%s", &field[i]);

    for(i= 0; i< m; i++) // 각 행과 열에 경비원이 몇명씩 있는지 체크
    {
        for(int j= 0; j< n; j++)
        {
            if(field[i][j]== 'X')
            {
                check1[i]++;
                check2[j]++;
            }
        }
    }

    for(i= 0; i< m; i++) if(check1[i]== 0) count[0]++; // 행에 경비원이 없는 행 카운트
    for(i= 0; i< n; i++) if(check2[i]== 0) count[1]++; // 열에''

    if(count[0]< count[1]) printf("%d", count[1]);
    else printf("%d", count[0]);

}
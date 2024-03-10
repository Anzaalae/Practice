#include <stdio.h>

int main()
{
    int count;
    scanf("%d", &count);

    int repeat[count];
    char input[count][21];
    char output[count][161];
    
    int check = 0;
    int edit = 0;

    for(int i =0; i <count; i++)
    {
        scanf("%d %s", &repeat[i], &input[i]);

        while(input[i][check] != '\0')
        {
            for(int j =0; j <repeat[i]; j++)
            {
                output[i][edit] = input[i][check];
                edit++;
            }
            check++;
        }

        output[i][edit] = '\0'; // 이게 뭔지 모르겠지만 이거 없으면 틀림;;

        edit =0;
        check =0;
    }

    for(int k =0; k <count; k++)
        printf("%s\n", output[k]);

}
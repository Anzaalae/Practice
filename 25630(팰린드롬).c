#include <stdio.h>
#include <malloc.h>

int main()
{
    int strLen;
    const char *str;

    int count = 0;

    scanf("%d", &strLen);
    str= (const char*)malloc(sizeof(char)*(strLen +1));

    scanf("%s", str);

    for(int i = 0; i < strLen/2; i++)
    {
        if(str[i] != str[strLen - (i+1)]) count++;
    }

    printf("%d", count);

    free(str);
}
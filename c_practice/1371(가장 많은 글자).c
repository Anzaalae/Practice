#include<stdio.h>
#include<string.h>

int main()
{
    char str[51][51];
	char ch[51];
	int i = 0;

    while (fgets(ch, 51,stdin)!= NULL)
    {
		strcpy(str[i], ch);
		i++;
	}

	int alpha[26]= {0};

	for(int j= 0; j< i; j++)
	{
		int kkkk=strlen(str[j]);
		for(int k= 0; k< kkkk; k++)
		{
			if(str[j][k]>= 'a' && str[j][k]<= 'z') alpha[str[j][k]-'a']++;
		}
	}
	
	int mostAlpha= alpha[0];

	for(int j= 1; j< 26; j++)
	{
		if(mostAlpha< alpha[j]) mostAlpha = alpha[j];
	}

	for(int j= 0; j< 26; j++)
	{
		if(alpha[j]== mostAlpha) printf("%c", j+ 'a');
	}
}

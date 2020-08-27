#include <stdio.h>
#include <string.h>
#define MAX 100

void get_next(char T[], int *next)
{
	int i,j;
	i=1;
	j=0;
	next[1]=0;
	while(i<T[0])
	{
		if(j==0 || T[i]==T[j])
		{
			++i;
			++j;
			next[i]=j;
		}
		else
			j=next[j];
	}
}

int Index_KMP(char S[], char T[], int pos)
{
	int i = pos;
	int j = 1;
	int next[MAX];
	get_next(T, next);
	while( i <= S[0] && j <= T[0])
	{
		if(j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			j=next[j];
		}
	}
	if(j > T[0])
		return i-T[0];
	else
		return 0;
}

void Input_String(char *string)
{
	char input[MAX]="";
	scanf("%s",input);
	int length=0;
	while(input[length]!='\0')
	{	
		length++;
	}
	string[0]=length;
}

void main(int argc, char * argv[])
{
	char S[MAX]="",T[MAX]="";
	int index=0;
	Input_String(S);
	Input_String(T);
	index=Index_KMP(S,T,4);
	printf("%d\n",index);
}

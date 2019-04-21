#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
	
char pilhas[30];
int c=1;

int verificarpilhas(char letra, int p)
{
	int i;
	for(i =0;i<p;i++)
	{
			if(letra <= pilhas[i])
			{
					pilhas[i]=letra;
					return 0;
			}
	}
	pilhas[i]= letra;
	return 1;
}

int main()
{
	char conteiners[1003];	
	int npilha=0;
	while(scanf("%s",conteiners) && strcmp(conteiners,"end")!=0)
	{
		int qtd = strlen(conteiners);
		for(int i =0;i<qtd;i++)
		{
			npilha = npilha + verificarpilhas(conteiners[i],npilha);
		}
		printf("Case %d: %d\n",c++,npilha);
		npilha=0;
	}
	return 0;
}

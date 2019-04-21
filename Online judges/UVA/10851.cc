#include <bits/stdc++.h>
using namespace std;

char h[1000][1000];

int main()
{
	//~ freopen("in","r",stdin);
	string a;
	int N;
	scanf("%d",&N);
	int m;
	while(N--)
	{
		scanf(" ");
		int i = 0;
		while(getline(cin,a) && a != "")
		{
			m = a.size();
			for(int j = 0; j < (int)a.size();j++)
				h[i][j] = a[j];
			i++;
		}
		
		int l = i;
		int soma;
		for(int j = 1; j < m-1 ; j++)
		{
			int sh = 1;
		    soma = 0;
			for(int i = 1; i < l; i++)
			{
				if(h[i][j] == '\\') soma += sh;
				sh <<= 1;
			}
			printf("%c",soma);
		}
		puts("");
	}
}

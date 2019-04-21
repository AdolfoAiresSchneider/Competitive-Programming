#include <bits/stdc++.h>
using namespace std;

int pesos[500];
int dp[500][500];
int N;
int soma;

bool mochila(int produto, int disp)
{
	
	if( disp == 0 ) return 1;
	if ( produto >= N ) return 0;
	if( dp[produto][disp] != -1 ) return dp[produto][disp];
	dp[produto][disp] = mochila( produto+1 , disp - pesos[produto] ) || mochila( produto+1 , disp );
    return  dp[produto][disp];
}

int main()
{
	string a;
	int casos,aux;
	scanf("%d",&casos);
	cin.ignore();
	while(casos--)
	{
		getline(cin,a);
		stringstream fluxo(a);
		soma = N=0;
		memset(dp,-1,sizeof dp);
		while(fluxo>>aux)
		{
			pesos[N++] = aux;
			soma+=aux;
		}
		if(soma%2 != 0)
		{
			printf("NO\n");
		}
		else
		{
			if(mochila(0,soma/2))
			{
				cout<<"YES"<<endl;	
			}
			else
			{
				printf("NO\n");		
			}
		}
	}
}

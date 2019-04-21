#include <bits/stdc++.h>
using namespace std;

int g[3];
int c[3];
int b[3];
int visited[3];

string resp;
int steps;
int SomaG,SomaB,SomaC;


void f(int caixa , string str, int soma)
{
	if(str.size() == 3)
	{
		if(soma < steps)
		{
			resp = str;
			steps = soma;
			return;
		}
	}
	if(caixa > 3 )return;
	
	if(!visited[1])
	{
		visited[1] = 1;
		f(caixa+1,str+"B", SomaB - b[caixa]+ soma );
		visited[1] = 0;
	}	
	if(!visited[2])
	{
		visited[2] = 1;
		f(caixa+1,str+"C", SomaC - c[caixa]+ soma );
		visited[2] = 0;
	}
	if(!visited[0])
	{ 
		visited[0] = 1;
		f(caixa+1,str+"G", SomaG - g[caixa]+ soma );
		visited[0] = 0;
	}
	
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	while(scanf("%d%d%d%d%d%d%d%d%d",&b[0],&g[0],&c[0],&b[1],&g[1],&c[1],&b[2],&g[2],&c[2]) != EOF)
	{
		memset(visited,0,sizeof visited);
		steps = 1e9;
		SomaB = b[0] + b[1] + b[2];
		SomaG = g[0] + g[1] + g[2];
		SomaC = c[0] + c[1] + c[2];
		f(0,"",0);
		cout<<resp<<' '<<steps<<endl;
	}
}

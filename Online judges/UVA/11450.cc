#include<bits/stdc++.h>
using namespace std;

int N,M,C,K,a;
vector<int> p[200];
int dp[400][400];


int f(int item, int disp)
{
	if(disp == 0 && item >= C ) return 0;
	else if(disp < 0 )return -1e9;
	int & r = dp[item][disp];
	if(r != -1) return r;
	r = 0;
	for(int i = 0; i <(int)p[item].size();i++)
		r = max( r , f(item+1,disp-p[item][i]) + p[item][i]);
	return r;
}

int main()
{
	//~ freopen("in","r",stdin);
	scanf("%d",&N);
	while(N--)
	{
		int minimo = 0,aux;
		scanf("%d%d",&M,&C);
		for(int i = 0; i <= C ; i++) p[i].clear();
		for(int j = 0 ; j < C ; j++)
		{
			aux = 1e9; 
			scanf("%d",&K);
			while(K--)
			{
				scanf("%d",&a);
				p[j].push_back(a);
				aux = min(aux,a);
			}
			minimo += aux;
		}
		memset(dp,-1,sizeof dp);
		int resp = f(0,M);
		if(resp >= minimo) cout<<resp<<endl;
		else puts("no solution");
	}
}

#include <bits/stdc++.h>
using namespace std;

int t,w,N;

int preco[40];
int depth[40];
set<int> obj;
int dp[1005][1005];	

int getTime(int time)
{
	return time*w+time*2*w;
}

int mochila(int Tdisp, int teasure)
{
	if(Tdisp <= 0 || teasure >= N) return 0;
	
	if(dp[Tdisp][teasure]!=-1) return dp[Tdisp][teasure];
	
	if(getTime(depth[teasure]) <= Tdisp) 
		dp[Tdisp][teasure] = max(preco[teasure]+mochila(Tdisp-getTime(depth[teasure]),teasure+1),mochila(Tdisp,teasure+1));	
	else dp[Tdisp][teasure] = mochila(Tdisp,teasure+1);
	
	return dp[Tdisp][teasure];
}

void rec(int Tdisp, int teasure)
{
	if(Tdisp <= 0 || teasure >= N) return ; // casos bases normais
	if(getTime(depth[teasure])<= Tdisp) // verificar se realmente usei o produto
	{
		if(mochila(Tdisp,teasure+1) == dp[Tdisp][teasure]) rec(Tdisp,teasure+1); // se eu nao usei apenas vou para o outro
		else{// usei e é a reposta ótima que ja esta armazenada
			obj.insert(teasure);
			rec(Tdisp-getTime(depth[teasure]),teasure+1);
		}
	}else{
		rec(Tdisp,teasure+1);// nao usei
	}
}

int main()
{
	int flag = 0;
	while(scanf("%d%d",&t,&w) != EOF)
	{
		memset(dp,-1,sizeof dp);
		scanf("%d",&N);
		for(int i = 0;i<N;i++)
		{
			scanf("%d%d",&depth[i],&preco[i]);
		}
		if(flag) puts("");
		flag =1;
		cout<<mochila(t,0)<<endl;
		rec(t,0);
		cout<<obj.size()<<endl;
		
		for(set<int>::iterator it = obj.begin(); it!=obj.end();it++)
		{
			printf("%d %d\n",depth[*it],preco[*it]);			
		}
		obj.clear();
	}	
}

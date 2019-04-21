#include <bits/stdc++.h>
using namespace std;

int t,w,N;

int v[40];
int we[40];
set<int> obj;
int dp[1005][1005];	

int getTime(int time)
{
	return time*w+time*2*w;
}

int dpIt(int N,int W)
{
	for(int i = 0; i <= N ; i++)
	{
		for(int p = 0; p <= W ; p++)
		{
			if(p == 0 || i == 0){
				dp[i][p] = 0; 
				continue;
			}
			dp[i][p] = dp[i-1][p];
			if(getTime(we[i-1]) <= p)
				dp[i][p] = max( v[i-1] + dp[i-1][ p - getTime(we[i-1])],dp[i][p]);
		}	
	}
	return dp[N][W];
}

void rec(int N, int W)
{
	if(!N) return;
	if(dp[N-1][W] == dp[N][W])
		return rec(N-1,W);
	obj.insert(N-1);
	rec(N-1,W - getTime(we[N-1]) );
}


int main()
{
	freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int flag = 0;
	while(scanf("%d%d",&t,&w) != EOF)
	{
		scanf("%d",&N);
		for(int i = 0;i<N;i++)
			scanf("%d%d",&we[i],&v[i]);
		if(flag++) puts("");
		cout<<dpIt(N,t)<<endl;
		rec(N,t);
		cout<<(int)obj.size()<<endl;
		for(set<int>::iterator it = obj.begin(); it!=obj.end();it++)
			printf("%d %d\n",we[*it],v[*it]);
		obj.clear();
		
	}	
}

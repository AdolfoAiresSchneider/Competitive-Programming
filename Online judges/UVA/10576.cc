#include <bits/stdc++.h>
using namespace std;

int mes[13];
int resp,ans,s,d;

void bk(int u)
{
	if(u > 4)
	{
		int sum = 0;
		for(int i = u - 5; i < u ; i++) sum += mes[i];
		if(sum >= 0 ) return;
	}
	
	if(u == 12)
	{
		int sum = 0;
		for(int i = 0 ; i < 12; i++) sum += mes[i];
		ans = max(sum,ans);
		return;
	}
	
	mes[u] = s;
	bk(u+1);
	mes[u] = -d;
	bk(u+1);
}

int main()
{
	while(scanf("%d%d",&s,&d) != EOF)
	{
		ans = -1e9;
		memset(mes,0,sizeof mes);
		bk(0);
		if(ans > 0) printf("%d\n",ans);
		else puts("Deficit");		
	}
}

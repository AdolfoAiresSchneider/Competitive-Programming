#include<bits/stdc++.h>
using namespace std;

int cubes[22];

void makecubes(){
	for(int i = 1; i <= 21;i++)	
		cubes[i-1] = i*i*i ;	
}

long int dp[23][10009];

int CC(int i, int disp)
{
	if(disp == 0) return 1;
	if( i >= 21 || disp < 0) return 0;
	if(dp[i][disp] != -1 ) return dp[i][disp];
	dp[i][disp] = CC(i+1,disp) + CC(i,disp-cubes[i]);
	return dp[i][disp];
}

int main()
{
	makecubes();
	int valor;
	memset(dp,-1,sizeof dp);
	
	while(scanf("%d",&valor)!= EOF)
	{
		cout<<CC(0,valor)<<endl;
	}
}

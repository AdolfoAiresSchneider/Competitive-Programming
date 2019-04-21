#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int N;
int cubos[506][10];
int dp[600][10];
vector<ii> resp;
map<int,string> id;
int longest;
ii filho[501];
int start ;

void lis(int cubo, int cor, int qtdc) // lis recursivo com reconstrução (Tipo dfs)
{
		for(int j = cubo + 1 ; j < N ; j++)
		{
			for(int k = 0; k < 6 ; k++)
			{
				if( cubo == -1 || ( cor == cubos[j][k] && dp[j][k] < qtdc+1 ) )
				{
					filho[qtdc] = ii(j,k); // coloca o filho
					dp[j][k] = qtdc + 1;
					lis( j , cubos[j][k^1] , qtdc+1 );
				}
			}	
		}
		
		if(qtdc > longest){
			longest = qtdc;
			for(int i = 0; i < qtdc;i++)
				resp[i] = filho[i];
		}
}


int main()
{
	//~ freopen("in","r",stdin);
	
	id[0] = "front"; id[1] = "back"; id[2] = "left"; id[3] = "right" ; id[4] = "top" ; id[5] = "bottom";
	
	int casos = 1,flag = 0;
	while(scanf("%d",&N) && N)
	{
		if(flag) cout<<endl;
		flag =1;
		resp.clear();
		resp.resize(500);
		memset(dp,0,sizeof dp);
		longest = 0;
		
		printf("Case #%d\n",casos++);
		
		for(int i = 0 ; i < N ; i++)
			for(int j = 0 ; j < 6 ; j++)
				scanf("%d",&cubos[i][j]);
				
		lis(-1,0,0);
		cout<<longest<<endl;
		
		for(int i = 0; i < longest ; i++)
			cout<<resp[i].first+1<<" "<<id[resp[i].second]<<endl;
	}
}

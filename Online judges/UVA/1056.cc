#include <bits/stdc++.h>
using namespace std;
// Apenas verificar o diametro de um grafo - flyoid warshal
const int inf = 0x3f3f3f3f;
int grafo[55][55];
map<string,int> id;

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	int N,M;
	string a,b;
	int casos =1;
	while(scanf("%d%d",&N,&M)&& (N||M))
	{
		memset(grafo,inf,sizeof grafo);
		id.clear();
		int k=1;
		
		while(M--)
		{
			cin>>a>>b;
		
			if(!id[a]) id[a] = k++;
			if(!id[b]) id[b] = k++;
			
			grafo[id[a]][id[b]] = grafo[id[b]][id[a]] = 1;
		}
		
		for(int k = 1; k <= N;k++)
			for(int i = 1; i <= N;i++)
				for(int j = 1; j <= N;j++)
					grafo[i][j] = min(grafo[i][j],grafo[i][k] + grafo[k][j]);
		
		int resp = -1e9;

		for(int i = 1; i <= N;i++) grafo[i][i] = 0;
		
		for(int i = 1; i <= N;i++)
				for(int j = 1; j <= N;j++)
					 resp = max(resp,grafo[i][j]);	
					
		printf("Network %d: ",casos++);
		if(resp == inf) cout<< "DISCONNECTED" <<endl<<endl;
		else  cout<< resp <<endl<<endl;		
	}
}

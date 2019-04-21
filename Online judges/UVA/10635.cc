#include <bits/stdc++.h>
using namespace std;
int N,P,Q;
int ord[63000];
int p2[63000];

inline int lis(int n)
{
	int L[n+2];
	int resp = 0;
	for(int i = 0 ; i <n ; i++){
		L[i] = 1;	
		for(int j = i-1 ; j > -1; --j) 
			if(p2[j] < p2[i] ) L[i] = max( L[j]+1,L[i]);
		resp = max(resp,L[i]);
	}
	return resp;
} 	


int main()
{
	//freopen("in","r",stdin);
	
	int casos,aux;
	int s = 1;
	scanf("%d",&casos);
	while(casos--)
	{
		scanf("%d%d%d",&N,&P,&Q);	
		for(int i = 0; i <= N*N+2;i++) ord[i] = -1;
		
		for(int i = 0; i <= P;++i){
			scanf("%d",&aux);
			ord[aux] = i;
		}
		
		int j = 0;
		for(int i = 0; i <= Q;++i){
			scanf("%d",&aux);
			if(ord[aux]!=-1) p2[j++] = ord[aux];
		}
		
		printf("Case %d: %d\n",s++,lis(j));
	}
}

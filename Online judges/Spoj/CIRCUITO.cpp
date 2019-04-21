#include<bits/stdc++.h>
using namespace std;
 
int mat[1004][1005];
 
int main()
{
	
	//~ freopen("in","r",stdin);
	int ans = 0,n,p , r;
	
	while(cin>>r>>n>>p && (r || n || p))
	{
	
		ans = 0;
		memset(mat,0,sizeof mat);
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < r; j++){
				scanf("%d",&mat[i][j]);
			}
		}
			
				
		for(int i = 0, j = 0 ; i < r ; i++)
		{
			j = 0;
			while(j < n)
			{
				int aux = 0;
				
				while(j < n && mat[j][i] == 1){
					j++;aux++;
				} j++;
				if(aux >= p) ans++;
			}
		}
		printf("%d\n",ans);
	}
} 

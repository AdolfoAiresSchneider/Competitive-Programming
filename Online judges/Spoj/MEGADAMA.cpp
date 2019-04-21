#include<bits/stdc++.h>
 
using namespace std;
typedef pair<int,int> ii;
 
int n,m, l,q , RESP;
#define maxn  500
 
int mat[maxn][maxn];
 
int dxx[] = {2,-2,-2,2};
int dyy[] = {2,-2,2,-2};
 
int dx[] = {1,-1,-1,1};
int dy[] = {1,-1,1,-1};
 
bool can (int i, int j, int ic, int jc)
{
	if (ic < n && jc < m && ic >= 0 && jc >= 0)
		if (mat[i][j] == 2 && mat[ic][jc] == 0)
			return true;
	return false;
}
 
void f(int x, int y, int sum)
{
	if(x > n || y > m || x < 0 || y < 0) return;
	
	for(int i = 0; i < 4; i++)
	{
		if(!can(x+dx[i], y + dy[i],x + dxx[i] , y + dyy[i])) continue;
		
		mat[x][y] = 0;
		mat[x+dx[i]][y+dy[i]] = 0;
		mat[x+dxx[i]][y+dyy[i]] = 1;
		f(x + dxx[i], y + dyy[i],sum+1);
		mat[x][y] = 1;
		mat[x+dx[i]][y+dy[i]] = 2;
		mat[x+dxx[i]][y+dyy[i]] = 0;
	}
	RESP = max(RESP,sum);
}
 
int main()
{
	
	//~ freopen("in","r",stdin);
	while(cin>>n>>m && (m || n))
	{
		vector<ii> v;
		
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				if ((i+j)%2 != 0) mat[i][j] = 3;
				else mat[i][j] = 0;
		memset(mat,0,sizeof mat);
				
		for (int i = 0; i < n; i++)
		{
			for (int j = i%2 ; j < m; j = j + 2)
			{
				int x;
				cin >> x;
				mat[i][j] = x;
				if (x == 1) 
					v.push_back(ii(i, j));	
			}
		}
			
		RESP = 0;
		for(int i = 0; i < (int)v.size(); i++)
			f(v[i].first,v[i].second, 0);
		cout<<RESP<<endl;
	}
	
}

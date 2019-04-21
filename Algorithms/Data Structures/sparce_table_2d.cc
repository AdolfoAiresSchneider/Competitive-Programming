#include<bits/stdc++.h>
using namespace std;

#define maxn 1003
#define LOG 10
#define inf 1e9

int p[maxn][LOG][maxn][LOG];
int a, b, n, m;

void process()
{
  // minimo para cada linha
  for(int l = 0; l < n; l++){
    for(int j = 1; j <= log2(m)+1; j++)
      for(int c = 0; c + (1<<j)-1 < m; c++)
        p[l][0][c][j] = min(p[l][0][c][j-1], p[l][0][c+(1<<(j-1))][j-1]);
  }
  
  // minimo considerando linhas e colunas
  for(int j1 = 1; j1 <= log2(n); j1++)
    for(int l = 0; l < n; l++)
      for(int j2 = 1; j2 <= log2(m); j2++)
        for(int c = 0; c < m; c++)
          p[l][j1][c][j2] = min(p[l][j1-1][c][j2], p[l+(1<<(j1-1))][j1-1][c][j2]);
}

// query
int query(int x1, int y1, int x2, int y2)
{
  int ans = inf;
  for(int j1 = log2(n); j1 >= 0; j1--){
    if(x1 + (1<<j1) - 1 <= x2){
      for(int j2 = log2(m)+1; j2 >= 0; j2--){
        if(y1 + (1<<j2) - 1<= y2){
          ans = min(ans, p[x1][j1][y1][j2]);
          y1 += 1<<j2;
        }
      }
      x1 += 1<<j1;
    }
  }
  
  return ans;
}

int main()
{
  freopen("in","r", stdin);
  
  cin>>n>>m>>a>>b;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin>>p[i][0][j][0];
      
  process();
  
  int q;
  cin>>q;
  while(q--)
  {
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;
    cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<' '<<query(x1,y1,x2,y2)<<endl;
  }   
}

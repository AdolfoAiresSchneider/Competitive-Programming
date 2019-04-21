#include <bits/stdc++.h>
using namespace std;
#define maxn 1001

char s[maxn], t[maxn];
int n, m, dp[maxn][maxn];

// Edit Distance e reconstrução !!!!!!!!!!!!
int edit_distance()
{
 for(int i = 0; i <= n; i++)
  dp[i][0] = i;
  
 for(int j = 0; j <= m; j++)
  dp[0][j] = j;
  
 for(int i = 1;i <= n; i++)
 {
  for(int j = 1; j <= m; j++)
  {
    int & r = dp[i][j];
    
    if(s[i-1]==t[j-1])
      r = dp[i-1][j-1];
    else r = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
  }
 }
 return dp[n][m];
}

void reconstruct()
{
 int i = n, j = m, cnt = 1;
 printf("%d\n", dp[i][j]);
 
 while(i || j)
 {
  if(i && j && s[i-1] == t[j-1]){
    i--, j--;
    continue;
  }
  
  if( i && dp[i-1][j]+1 == dp[i][j]){
    cout<<cnt++<<" Delete "<<i<<endl;
    i--;
    continue;
  }
  
  if(i && j && dp[i][j] == dp[i-1][j-1]+1){
    cout<<cnt++<<" Replace "<<i<<","<<t[j-1]<<endl;
    i--, j--;
    continue;
  }
  
  if(j){
    cout<<cnt++<<" Insert "<<i+1<<","<<t[j-1]<<endl; j--;
  }
 }
}

int main()
{
 bool flag = false;
 while(scanf(" %s %s",s,t) == 2)
 {
    n = strlen(s), m = strlen(t);
    
    if(flag) cout<<endl;
    flag = true;
    
    edit_distance();
    reconstruct();
 }
}

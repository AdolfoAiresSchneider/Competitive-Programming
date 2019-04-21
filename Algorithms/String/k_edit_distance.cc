#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define maxn 100010
#define maxk 250

char s[maxn], t[maxn];
int dp[maxn][maxk], a, b, k, n, m, casos, offset = 200;

// Edit distance com no maximo custo K, onde as operações possuem custo.
int k_edit_distance()
{
  memset(dp, INF, sizeof dp);
    
  for(int i = 0; i <= 100; ++i)
    dp[i][offset-i] = i * a;
  
  for(int i = 1; i <= 100; ++i)
    dp[0][offset+i] = i * a;
    
  for(int i = 1; i <= n; ++i)
  {
    for(int d = -k; d <= k; ++d)
    {
      int & r = dp[i][offset+d];
      if(s[i-1] == t[i+d-1]) 
        r = dp[i-1][offset+d];
      else r = min(min(dp[i-1][offset+d+1], dp[i][offset+d-1]) + a, dp[i-1][offset+d] + b);
    }
  }
  
  return dp[n][m - n + offset];
}

int main()
{
    scanf("%d", &casos);
    while(casos--)
    {
      scanf("%s %s", s, t);
      scanf("%d %d %d", &a, &b, &k);
      n = strlen(s), m = strlen(t);

      if(a == 0){
          puts("0");
          continue;
      }

      if(abs(n - m) * a > k){
          puts("-1");
          continue;
      }
    
      int ans = k_edit_distance();
      
      if(ans <= k) printf("%d\n", ans);
      else puts("-1");
    }
}

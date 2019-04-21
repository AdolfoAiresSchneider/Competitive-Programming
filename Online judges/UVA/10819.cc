#include <bits/stdc++.h>
using namespace std;
 
int m, n;
int p[110];
int favour[110];
int dp[110][15009];
 
int mochila(int i, int usado) 
{
    if(usado > m + 200 || (usado > m && m <= 1800) ) return -1e9; // se não da pra comprar
    if(i >= n) 
    {
        if(usado > m && usado <= 2000) return -1e9; // não tenho credito
        return 0; // tenho credito
    }
    int & r = dp[i][usado];
    if(r != -1) return r;
    return r = max(mochila(i + 1, usado),favour[i] + mochila(i + 1, usado + p[i]));
}
 
int main() 
{
	//freopen("in","r",stdin);
    while(scanf("%d %d", &m, &n) != EOF ) 
    {
		for(int i = 0; i < n; i++)
            scanf("%d %d", &p[i], &favour[i]);
        memset(dp, -1, sizeof dp);
        printf("%d\n", mochila(0, 0));
    }
   }

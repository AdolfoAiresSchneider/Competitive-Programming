#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6;

int dp[1000004];

int f(int n)
{
	if (n == 0) return 1;
  int & r = dp[n];
	if (dp[n]!=-1) return r;
	r = 0;
	r += (f((int)floor(n-sqrt(n))) + f((int)floor(log(n))))%mod;
  r = r%mod
	r += f((int)floor(n*sin(n)*sin(n)));
  r = r%mod
	return r;
}

int main()
{
	int n;
  memset(dp,-1,sizeof dp);
	while (cin >> n && n)
		cout << f(n) << endl;
}

#include<bits/stdc++.h>
using namespace std;

#define maxn 100000

int z[maxn], p[maxn];

void  z_function(string s)
{
    int n = s.length();
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

int distinct_substrings(string s) // <= n^2
{
  int ans = 0, n = s.size();
  for(int i = 0; i <= n-1; i++)
  {
    string x = s.substr( 0 , i+1 );
    reverse( x.begin() , x.end() );
    z_function( x );
    int mx = 0;
    for(int j = 0; j < (int)x.size(); j++)
      mx = max(mx, z[j]);
    ans += (i+1) - mx; 
  }
  return ans;
}

void z_to_kmp(int n)
{
	for(int i = n-1; i >= 0;i--)
  {
		if (z[i] == 0) {p[i] = 0; continue;}
		if (z[i] == 1) {p[i] = 1; continue;}
		
		p[i+z[i]-1] = max(p[i+z[i]-1], z[i]);
		p[i] = max(1, p[i]);	
	}

	int last = p[n-1]-1;
	for(int i = n-2; i >= 0;i--)
  {
		p[i] = max(p[i], last);
		last = max(last, p[i]);
		last--;
	}
}

int main()
{
  
}

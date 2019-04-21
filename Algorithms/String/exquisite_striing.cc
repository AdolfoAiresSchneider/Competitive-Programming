#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define maxn 100009
#define mod 1000000007

// Numero de pares de substrings que tem um prefixo de no minimo tamanho k

vi suffix_array(string s) // O(n) build
{
    int n = s.size(), N = n + 256;
    vi sa(n), ra(n);
    for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
    for(int k = 0; k < n; k ? k *= 2 : k++)
    {
        vi nsa(sa), nra(n), cnt(N);
        for(int i = 0; i < n; i++) nsa[i] = (nsa[i] - k + n) % n;
        for(int i = 0; i < n; i++) cnt[ra[i]]++;
        for(int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];
 
        int r = 0;
        for(int i = 1; i < n; i++)
        {
            if(ra[sa[i]] != ra[sa[i - 1]]) r++;
            else if(ra[(sa[i] + k) % n] != ra[(sa[i - 1] + k) % n]) r++;
            nra[sa[i]] = r;
        }
        ra = nra;
    }
    return sa;
}

vi kasai(string s, vi sa) // O(n) build
{
    int n = s.size(), k = 0;
    vi ra(n), lcp(n);
    for(int i = 0; i < n; i++) ra[sa[i]] = i;
    for(int i = 0; i < n; i++)
    {
        if(k) k--;
        if(ra[i] == n - 1) {k = 0; continue;}
        int j = sa[ra[i] + 1];
        while(k < n && s[(i + k) % n] == s[(j + k) % n]) k++;
        lcp[ra[i]] = k;
        if(ra[(sa[ra[i]] + 1) % n] > ra[(sa[ra[j]] + 1) % n]) k = 0;
    }
    return lcp;
}


ll k , t, c = 1;
vi sa, lcp;
string str;

ll solve(int k)
{
  ll ans = 0, n = sa.size();
  for(int i = 0 ; i < n;)
  {
    ll sum = n-sa[i]-k, cnt = 0;
    if(sum > 0)
    {
      cnt = (sum*(sum-1)/2ll)%mod; i++;
      
      while(i < n && lcp[i-1] >= k)
      {
        ll t = n-sa[i]-k;
        cnt = (cnt + sum*t % mod + (t*(t-1)/2ll)%mod)%mod;
        sum = (sum+t%mod)%mod;
        i++;
      }
      ans = (ans + cnt)%mod;
    }else i++;
  }
  return ans;
}

int main()
{
  //~ freopen("in", "r", stdin);
  cin>>t;
  
  while(t--)
  {
    cin>>str>>k;
    str += '#'; 
    sa = suffix_array(str);
    lcp = kasai(str, sa);
    
    cout<<"Case #"<<c++<<": "<<solve(k)<<endl;
  }
}

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define pb push_back
#define maxn 600020
#define sz(x) (ll)x.size()
typedef vector<int> vi;

vi lcp, sa;
 
ll b[maxn], p[maxn];
void processKmp(string s){
  b[0] = 0;
  for(ll i = 1; i < sz(s); i++){
    ll x = b[i-1];
    while(x > 0 && s[i] != s[x])  x = b[x];
    if(s[x] == s[i]) x++;
    b[i] = x;
  }
}
 
void kmp(string s, string pt){
  ll x = 0, m = sz(pt);
  for(ll i = 0; i < sz(s); i++){
    while(x && s[i] != pt[x]){
       x = b[x];
    }
    if(s[i] == pt[x]) x++;
    if(x == m) {
      p[i-1] = 1, x = b[x];
    }
  }
  
  for(ll i = sz(s); i >= 0; i--){
    p[i] += p[i+1];
  }
}
 
vi suffix_array(string s)
{
    ll n = s.size(), N = n + 256;
    vi sa(n), ra(n);
    for(ll i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
    for(ll k = 0; k < n; k ? k *= 2 : k++)
    {
        vi nsa(sa), nra(n), cnt(N);
        for(ll i = 0; i < n; i++) nsa[i] = (nsa[i] - k + n) % n;
        for(ll i = 0; i < n; i++) cnt[ra[i]]++;
        for(ll i = 1; i < N; i++) cnt[i] += cnt[i - 1];
        for(ll i = n - 1; i >= 0; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];
 
        ll r = 0;
        for(ll i = 1; i < n; i++)
        {
            if(ra[sa[i]] != ra[sa[i - 1]]) r++;
            else if(ra[(sa[i] + k) % n] != ra[(sa[i - 1] + k) % n]) r++;
            nra[sa[i]] = r;
        }
        ra = nra;
    }
    return sa;
}
 
 
vi kasai(string s, vi sa)
{
    ll n = s.size(), k = 0;
    vi ra(n), lcp(n);
    for(ll i = 0; i < n; i++) ra[sa[i]] = i;
    for(ll i = 0; i < n; i++)
    {
        if(k) k--;
        if(ra[i] == n - 1) {k = 0; continue;}
        ll j = sa[ra[i] + 1];
        while(k < n && s[(i + k) % n] == s[(j + k) % n]) k++;
        lcp[ra[i]] = k;
        if(ra[(sa[ra[i]] + 1) % n] > ra[(sa[ra[j]] + 1) % n]) k = 0;
    }
    return lcp;
}
 
ll solve(string & str, int idT1, int m, int n){
	
	sa = suffix_array(str);
  lcp = kasai(str, sa);
  
  int idx = -1;
  for(int i = 0; i < sz(sa); i++){
    if(sa[i] == idT1){
      idx = i; break;
    }
  }
  
  int l = idx, r = idx;
  for(; l >= 0 && lcp[l] >= m; l--); l+= 2;
  for(; r < sz(lcp) && lcp[r] >= m; r++);
  
  if(r < l) return 0;
  
  ll ans = p[sa[l]+max(m-1, n-1)];
  for(int i = l+1; i <= r; i++){
    int id = sa[i] + lcp[i-1];
    id = max(id, sa[i] + n-1);
    ans += p[id];
  }
  
  return ans;
}
 
int main(){
	
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  string s, t1, t2;
  while(cin>>s>>t1>>t2){
    
    memset(p, 0, sizeof p);
    
    processKmp(t2);
    kmp(s, t2);
    
    string str = s + "@";
    int idT1 = str.size();
    str += t1 + "#";
    
    cout<<solve(str, idT1, sz(t1), sz(t2))<<endl;
  }
}


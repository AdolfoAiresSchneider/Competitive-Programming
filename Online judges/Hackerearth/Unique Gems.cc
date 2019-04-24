#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define pb push_back
#define sz(x) (ll)x.size()
typedef vector<int> vi;

vi lcp, sa;
vi suffix_array(string s){
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
 
 
vi kasai(string s, vi sa){
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

ll solve(string s){
  sa = suffix_array(s);
  lcp = kasai(s, sa);
  int n = sz(s)-1;
  
  ll ans = 0;
  for(int i = 1; i < sz(lcp); i++){
    int mx = 0;
    if(i) mx = max(mx, lcp[i-1]);
    mx = max(mx, lcp[i]);
    ans += max((n - (sa[i] + mx)), 0);
  }
  return ans;
}
 
int main(){
	
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  int t;
  cin>>t;
  while(t--){
    string str;
    cin>>str;
    cout<<solve(str + '$')<<endl;
  }
  
}

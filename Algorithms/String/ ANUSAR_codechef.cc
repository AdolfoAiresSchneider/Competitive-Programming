#include<bits/stdc++.h>
using namespace std;

//  Calcula o numero de substrings que aparecem no minimo i vezes, ans[i] tem essa informação


typedef long long ll;
typedef vector<ll> vi;

#define inf 0x3f3f3f3f
#define maxn 300009
#define endl '\n'
#define pb push_back

vi suffix_array(string s) // O(n) build
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
 
vi kasai(string s, vi sa) // O(n) build
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

vi lcp, sa, idx[maxn];
ll t, n, l[maxn], r[maxn], ans[maxn], q;
set<ll> sizes;

// Limite inferior e superior que o lcp se mantem.

void processRange()
{
  stack<ll> p;
  
  for(ll i = 0; i < n-1; i++){
    while(p.size() && lcp[i] <= lcp[p.top()])
      p.pop();
    l[i] = (p.size() ? p.top() : -1);
    p.push(i);
  }  
  
  while(p.size()) p.pop();
  
  for(ll i = n-2; i >= 0; i--){
    while(p.size() && lcp[i] <= lcp[p.top()])
      p.pop();
    r[i] = (p.size() ? p.top() : n-1);
    p.push(i);
  }
}

// Utiliza os limites para atualizar ans[i], sendo i = r[k] - l[k], ou seja a substring aparece com frequencia i
// É necessario tratar 2 overlap problems : 
//  1 - Lcp ja considerado nesse intervalo (mantem um ponteiro para o proximo lcp a ser processado, e nao processa nenhum que ja foi)
//  2 - Substrings ja contadas em intervalos vizinhos (pega o min(lcp[x], lcp[x] - l[k] , lcp[x] - r[k]), ou seja apenas o lcp unico desse range)

void solve()
{
  for(ll i = 0 ;i < n-1; i++){
    idx[lcp[i]].pb(i);
    sizes.insert(-lcp[i]);
  }
  
  for(auto v : sizes)
  {
    ll i = -v, j = 0;
    while(j < (ll)idx[i].size())
    {
      ll cur = i, k = idx[i][j];
      
      if(l[k] != -1)
        cur = min(cur, i - lcp[l[k]]);
      
      if(r[k] != n-1)
        cur = min(cur, i - lcp[r[k]]);
      
      ll range = r[k] - l[k];
      ans[range] += range * cur;
      
      while(j < (ll)idx[i].size() && idx[i][j] < r[k]) j++;
    }
  }
  
  for(ll i = n-2; i >= 0; i--)
    ans[i] += ans[i+1]; 
    
  ans[1] = (n-1)*((n-1)+1ll)/2ll;
}

void init(ll n){
   for(ll i = 0; i <= n+9 ; i++)
      idx[i].clear();
    memset(ans, 0, sizeof ans);
    sa.clear(), lcp.clear(), sizes.clear();
}


int main()
{
  //~ freopen("in","r",stdin);
  
  cin.sync_with_stdio(0), cin.tie(0);
  cin>>t;
  
  while(t--)
  {
    
    string str;
    cin>>str>>q; 
    str += '#';
    n = str.size();
    init(n);
    
    sa = suffix_array(str);
    lcp = kasai(str, sa);
    
    processRange();
    solve();
    
    while(q--){
      ll f;
      cin>>f;
      cout<<ans[f]<<endl;
    }
  }
  return 0;
}

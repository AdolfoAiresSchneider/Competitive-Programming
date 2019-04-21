#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

#define maxn 1400000
#define pb push_back
#define mod 1000000007
#define st first
#define nd second
#define iii(a,b,c) iii(a, ii(b,c))

vi sa, ra;
void suffix_array(vi & s)
{
    
    int n = s.size(), N = n + 256;
    
    sa.resize(n,0); ra.resize(n,0);
    
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
}

int id[maxn], ordem[maxn], n, k, size[maxn];
vi st[maxn];

ll solve()
{
  priority_queue<iii, vector<iii>, greater<iii> > pq;
  
  for(int i = 0; i < n; i++)
  {
    if(st[i].size())
    {
      int x = st[i].back(); st[i].pop_back();
      int id_sa = id[i] + (size[i]-st[i].size());
      pq.push(iii(x, ordem[id_sa], i));    
    }
  }
  
  ll ans = 0;
  while(pq.size())
  {
    int num = pq.top().st, stk = pq.top().nd.nd; pq.pop();
    ans = (ans*365ll%mod + num)%mod;
    
    if(st[stk].size() > 1){
      int x = st[stk].back(); st[stk].pop_back();
      int id_sa = id[stk] + (size[stk]-st[stk].size());
      pq.push(iii(x, ordem[id_sa], stk));    
    }
  }
  
  return ans*365ll%mod;
}

int main()
{
  //~ freopen("in", "r", stdin);
  
  while(scanf("%d",&n) == 1)
  {
    vi str;
    for(int i = 0; i < n; i++)
    {
      vi aux;
      scanf("%d",&k);
      size[i] = k;
      
      while(k--){
       int x;
       scanf("%d",&x);
       aux.pb(x);
      } 
     
      aux.pb(302);
      
      id[i] = str.size();
      for(auto v : aux)
        str.pb(v);
        
      reverse(aux.begin(), aux.end());
      st[i] = aux;
    }
    
    suffix_array(str);
    
    for(int i = 0; i < (int)sa.size(); i++){
      ordem[sa[i]] = i;  
    }
    
    ll ans = solve();
    printf("%lld\n", ans);
  }  
}

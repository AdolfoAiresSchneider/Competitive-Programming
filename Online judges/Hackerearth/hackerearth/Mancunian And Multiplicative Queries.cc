#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define maxn 1000009
#define mod 1000000007
#define pb push_back

ll A[maxn], freq[maxn], func[maxn], ans = 1, n, c, q;

struct query{
  ll l, r, id;
  bool operator < (query const & other) const {
    ll b1 = r/sqrt(n), b2 = other.r/sqrt(n);
    if(b1 != b2) return b1 < b2;
    return l < other.l;
  }
};

ll fpow(ll x, ll y){
  if(!y) return 1;
  if(y%2) return x*fpow(x, y-1)%mod;
  ll aux = fpow(x, y/2);
  return aux*aux%mod;
}

vector<query> ranges;
ll cur = 1;

void add(ll x){
  cur *= fpow(func[freq[x]], mod-2);
  cur %= mod;
  freq[x]++;
  cur *= func[freq[x]];
  cur %= mod;
}

void rem(ll x){
  cur *= fpow(func[freq[x]], mod-2);
  cur %= mod;
  freq[x]--;
  cur *= func[freq[x]];
  cur %= mod;
}

void process(){
  cur = fpow(func[0], c);
  sort(ranges.begin(), ranges.end());
  ll i = 1, j = 0;
  for(auto x : ranges){
    while(j < x.r) add(A[++j]);
    while(i > x.l) add(A[--i]);
    while(i < x.l) rem(A[i++]);
    while(j > x.r) rem(A[j--]);
    ans *= cur;
    ans %= mod;
  }
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  cin>>n>>c>>q;
  
  for(ll i = 1; i <= n; i++) cin>>A[i];
  for(ll i = 0; i <= n; i++) cin>>func[i];
  
  for(ll i = 0; i < q; i++){
    ll l, r;
    cin>>l>>r;
    ranges.pb({l,r,i});
  }
  
  process();
  cout<<ans<<endl;
}

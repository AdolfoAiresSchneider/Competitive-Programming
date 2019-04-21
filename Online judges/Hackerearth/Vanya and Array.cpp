#include <bits/stdc++.h>
using namespace std; 
 
typedef  long ll;
typedef pair<ll,ll> ii;
 
#define all(x) x.begin(), x.end()
#define maxn 1000009
#define A(x) 2*x
#define B(x) (2*x+1)
#define pb push_back
#define endl '\n'
#define sz(x) (ll)x.size()
 
ll n, k, p[maxn], bit[maxn], t[maxn];
vector<ll> q, f;

int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


 
void reMap(){
  sort(all(q));
  for(int i = 0; i  < n; i++){
    p[i] = lower_bound(all(q), p[i]) - q.begin()+1;
  }
}
 
void update(ll idx, ll x){
  for(; idx <= n; idx += (idx&-idx)){
    bit[idx] += x;
  }
}
 
ll query(ll idx){
  ll sum = 0;
  for(; idx > 0; idx -= (idx&-idx)){
    sum += bit[idx];
  }
  return sum;
}
 
int main(){
  
  //~ freopen("in", "r", stdin);
  
  n = readInt();
  k = readInt();
  for(ll i =  0; i < n; i++){
    p[i] = readInt();
    q.pb(p[i]);
  }
  
  reMap();
  for(ll i = n-1; i >= 0; i--){
    ll idx = p[i];
    ll x = query(n+1)-query(idx);
    f.pb(x);
    update(idx, 1);
  }
  
  sort(all(f));
  ll ans = 0;
  for(ll i = 0; i < n; i++){
    ll x = f[i];
    ll idx = lower_bound(all(f), max(k-x,0l))- f.begin();
    idx = max(idx, i+1);
    if(idx == n) continue;
    ans += n-idx;
  }
  printf("%ld\n",ans);
}
 


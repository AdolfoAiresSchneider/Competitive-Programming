#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<ll, ii> iii;
 
#define iii(a,b,c) iii(a,ii(b,c))
#define maxn 1000009
#define mod 1000000000
 
 
vector<iii> ed;
ll p[maxn], nv[maxn];
 
ll find(ll u)
{
	if(u == p[u])
		return u;
	return p[u] = find(p[u]);
}
 
int main()
{
	//~ freopen("in", "r", stdin);
	
	ll n, m;
	cin>>n>>m;
	
	for(ll i = 0; i <= n; i++)
		p[i] = i, nv[i] = 1;
	
	
	for(ll i = 0; i < m; i++)
	{
		ll a, b, c;
		cin>>a>>b>>c;
		ed.push_back(iii(c,a,b));
	}
	
	sort(ed.rbegin(), ed.rend());
	
	ll ans = 0, t = 0;
	
	for(auto c : ed)
	{
		ll u = c.second.first;
		ll v = c.second.second;
		ll cost = c.first;
		
		if(find(u) != find(v))
		{
			t +=  nv[find(v)] * nv[find(u)]%mod;
			t %= mod;
			
			if(t < 0)
				t += mod;
			
			nv[find(v)] += nv[find(u)];
			p[find(u)] = find(v);
			
			ans = (ans + t*cost%mod)%mod;
			
		} else  ans = (ans + cost * t % mod)%mod;
	}
	
	cout<<ans%mod<<endl;
}

#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;
#define maxn 300009
 
 
vector<ll> suffix_array(string s)
{
    ll n = s.size(), N = n + 256;
    vector<ll> sa(n), ra(n);
    for(ll i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
    for(ll k = 0; k < n; k ? k *= 2 : k++)
    {
        vector<ll> nsa(sa), nra(n), cnt(N);
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
 
vector<ll> kasai(string s, vector<ll> sa) // O(n) build
{
    ll n = s.size(), k = 0;
    vector<ll> ra(n), lcp(n);
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
 
ll n, k, ans[30];
 
ll len(ll i)
{
	return n-i-1;
}
 
void dsr(vi & lcp, vi & sa, string & str)
{
	for(ll i = 0; i < (ll)sa.size()-1; i++ )
		ans[str[sa[i+1	]]-'a'] += len(sa[i+1]) - lcp[i]+1;
}
 
 
int main()
{
	cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  
  string str;
	cin>>str;
	n = str.size();
	str += '#';
	
	vi sa = suffix_array(str);
	
	vi lcp = kasai(str, sa);
	dsr(lcp, sa, str);
	
	for(ll i = 0; i < 26; i++){
		cout<<ans[i];
		if(i < 25) cout<<' ';
	}
}
 

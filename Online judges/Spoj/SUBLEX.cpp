#include<bits/stdc++.h>
using namespace std;
 
typedef vector<int> vi;
typedef long long ll;
#define maxn 100009
#define endl '\n'
 
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
 
 
vi kasai(string s, vector<int> sa) // O(n) build
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
 
int n, p[maxn], q;
string str;
vi sa, lcp;
 
int len(int i, int n)
{
  return n-i;
}
 
void process()
{   
  str += '#';
  n = str.size();
  sa = suffix_array(str);
  lcp = kasai(str, sa);
  
  for(int i = 0; i < n-1; i++){
    p[i] = (len(sa[i+1], n) - lcp[i]-1) + (i != 0)*p[i-1];
  }
}
 
string query(int k)
{
  int idx = lower_bound(p, p+n, k) - p;
  int t = p[idx-1]*(idx > 0);
 
  if(k > t) k -= t;  
    
  string ans = str.substr(sa[idx+1], lcp[idx]+k);
  
  if(ans.back() == '#'){
    ans = string(ans.begin(), ans.end()-1);
  }
  
	return ans;	
}
 
int main()
{
  cin.sync_with_stdio(0), cin.tie(0);
  
  cin>>str>>q;
  process();
  
  while(q--)
  {
	  int k;
	  cin>>k;
	  cout<<query(k)<<endl;  
  }
  return 0;
}

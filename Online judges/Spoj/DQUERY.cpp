#include <bits//stdc++.h>
using namespace std;
typedef pair<int,int> ii;
 
#define maxn 1000010
#define block 174
 
//~ int block;
 
struct querie
{
	int l,r,idx;
	querie( int l, int r, int idx) : l(l),r(r),idx(idx){}
	querie(){}
} q[200010];
 
int v[30010];
int freq[maxn];
 
int ans = 0;
int finalAns[maxn];
 
bool cmp(querie x, querie y)
{
	if(x.l/block != y.l/block)
		return x.l/block < y.l/block;
	return x.r < y.r;
		
}
 
 
void add(int idx) 
{
	freq[v[idx]]++;
	if(freq[v[idx]] == 1)
		ans++;
}
 
void remove(int idx)
{
	freq[v[idx]]--;
	if(freq[v[idx]] == 0)
		ans--;
}
 
int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin>>n;
	
	
	for(int i = 0; i < n; i++)
		cin>>v[i];
	
	int m;
	cin>>m;
	
	for(int i = 0; i < m ; i++)
	{
		cin>>q[i].l>>q[i].r;
		q[i].l--;q[i].r--;
		q[i].idx = i;
	}
	
	sort(q,q+m,cmp);
	
	int cr = 0, cl = 0;
	
	for(int i = 0; i < m; i++)
	{
		int L = q[i].l;
		int R = q[i].r;
		
        while(cl<L)
            remove(cl),cl++;
            
        while(cl>L)
            add(cl-1),cl--;
            
        while(cr<=R)
            add(cr),cr++;
            
        while(cr>(R+1))
            remove(cr-1),cr--;
                   
		finalAns[q[i].idx] = ans;
	}
		
	for(int i = 0; i < m;i++)
		cout<<finalAns[i]<<'\n';
	return 0;
}
 

#include <bits/stdc++.h>
using namespace std;
 
#define maxn 1000003
 
string s;
int p[maxn	];
 
int kmp(int n)
{
	p[0] = -1;
	for(int i = 1 ; i < n; i++)
	{
		int x = p[i-1];
		while(x != -1 && s[i] != s[x+1])
			x = p[x];
			
		if(x == -1)
			p[i] = (s[i] == s[0] ? 0 : -1);	
		else p[i] = x+1;
	}	
	return p[n-1];
}
 
 
int main()
{
	//~ freopen("in", "r", stdin);
	
	while(cin>>s && s != "*")
	{	
		int n = s.size();
		
		cout<<(n%(n-kmp(n)-1) == 0 ? n/(n-kmp(n)-1) : 1)<<endl;
	}	
}

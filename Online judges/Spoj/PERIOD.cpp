#include <bits/stdc++.h>
using namespace std;
 
#define maxn 1000003
 
string s;
int p[maxn];
 
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
	int casos, t = 1;
	cin>>casos;
	
	while(casos--)
	{
		cout<<"Test case #"<<t++<<endl;
		
		int n ;
		cin>>n>>s;
		
		kmp(n);
		
		for(int i = 1; i < n; i++)
		{
			int l = p[i];
			if((i+1)%((i+1)-l-1) == 0 && (i+1)/((i+1)-l-1) != 1)
				cout<<i+1<<' '<<(i+1)/((i+1)-l-1)<<endl;
		}
		if(casos)
			cout<<endl;
	}
}
 

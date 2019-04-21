#include <bits/stdc++.h>
using namespace std;
 
int t, n;
int main()
{
	
	//~ freopen("in","r",stdin);
	int acp, maxPontos;
	
	while(cin>>t>>n && (n || t))
	{
		maxPontos = n * 3;
 
		acp = 0;
		for (int i = 0; i < t; i++)
		{
			string a;
			int p;
			cin>>a>>p;
			acp += p;
		}
		cout << maxPontos - acp<<endl;
	}
}           
 

#include <bits/stdc++.h>
using namespace std;
vector<int> v;
 
int main()
{
	int n,nt,nt2,partes=1;
	cin>>n;
	
	while(n--)
	{
		cin>>nt;
		v.push_back(nt);
	}
    
    nt2 = v[0];
	int r2 = 0;
	int comp = 0;	
	
	for(int i = 1; i <(int)v.size();i++)
	{
		int r = v[i]-nt2;
		if(comp > 0 && r != r2)
		{
			partes++;
			r2 = 0;
			comp = 0;
			nt2 = v[i];
			continue;			
		}
		r2 = r;
		comp++;
		nt2 = v[i];
	}
	cout<<partes<<endl;
}
 

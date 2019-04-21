#include <bits/stdc++.h>
using namespace std;

int main()
{
	//~ freopen("in","r",stdin);
	string a;
	int n,i,j,k,c1,c2,c3;
	scanf("%d",&n);
	while(n--)
	{
		bool flag = 1;
		cin>>a;
		if(a.find('M') > a.find('E')) flag = 0;
		c1 = c2 = c3 = 0;
		
		for(i = 0; i < (int)a.size() && a[i]!= 'M' && flag;i++)
			if(a[i] == '?') c1++;
			else flag = 0;
		for(j = i+1; j < (int)a.size() && a[j] != 'E' && flag;j++)
			if(a[j] == '?') c2++;
			else flag =0;
		for(k = j+1; k < (int)a.size() && flag;k++)
			if(a[k] == '?') c3++;
			else flag = 0;
		
		if((c1 + c2) != c3) flag = 0;
		if(!c1 || !c2 || !c3) flag = 0;
		
		if(flag) puts("theorem");
		else puts("no-theorem");	
			
	}
}

#include <bits/stdc++.h>
using namespace std;
// so verificar todos os opostos de cada variavel dentro de cada um dos &
int main()
{
	//~ freopen("in","r",stdin);
	int n;
	string a,b,c;
	scanf("%d",&n);
	bool flag;
	while(n--)
	{
		flag = 0;		
		cin>>a;
		for(int i = 0; i < (int)a.size();i++)
			if(a[i] == '|' || a[i] == '(' || a[i] == ')') a[i] = ' ';
		stringstream fluxo(a);
		
		while(fluxo>>b)
		{
			bool aux = 1;
			for(int i = 0 ; i < (int)b.size();i++)
				if(b[i] == '&') b[i] = ' ';
			stringstream f2(b);
			while(f2 >> c)
			{
				if(c.size() == 1)
					if(b.find('~'+c) != string::npos)
					{
						aux = 0;
						break;
					}
			}	
			flag |= aux;
		}
		if(flag) puts("YES");
		else puts("NO");
	}
}

#include <bits/stdc++.h>
using namespace std;

#define Maxn 100

string m;
int b[Maxn];

int processKMP()
{
	int i = 0 ,  j = -1;  b[0] = -1;
	while(i < (int)m.size())
	{
		while( j >= 0 && m[i]!=m[j]) j = b[j];
		j++;i++;
		b[i] = j;
	}
	return j; // m[j] adiante possui a menor string que é usada para se formar a string grande !
}

int kmp()
{
		
}

int main()
{
	//~ freopen("out","w",stdout);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		getline(cin,m);
		memset(b , 0 , sizeof b);
		
		int l = m.size();
		int t = processKMP();
		cout<<" >> "<<t<<endl;
		if(l%(l-t)) cout<<l<<endl;
		else cout<<l-t<<endl;
		if(n) puts("");
		
		for(int i = 0 ; i < (int)m.size(); i++) cout<<b[i]<<' ';
		puts("" );
	}
}

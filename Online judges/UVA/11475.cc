#include <bits/stdc++.h>
using namespace std;
#define Maxn 1000004

// PEGA A MAIOR SUBSTRING DA REVERSE(AUX) QUE É UM PALINDROMO DE AUX E CONCATENA

string m,aux;
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
	return j;
}

int main()
{
	//~ freopen("i","r",stdin);
	while(cin>>aux)
	{
		m = string(aux.rbegin(),aux.rend()) + '#' + aux;
		int l = processKMP();
		cout<<aux + string(aux.rbegin()+l,aux.rend())<<endl;
	}
}

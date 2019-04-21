#include <bits/stdc++.h>
using namespace std;
#define MaxN 1000001

int b[MaxN];
string m,n;

int processKmp()
{
	int i = 0, j = - 1; b[0] = -1;
	while(i < (int)m.size())
	{
		while(j >= 0 && m[i] != m[j]) j = b[j];
		j++; i++;
		b[i] = j;
	}
	return j;
}


int main()
{
	while(cin>>m && m != "." )
	{	
		memset( b , 0 , sizeof b);
		int tam = processKmp();
		cout<<tam<<endl;
		cout<<(int)m.size()/((int)m.size()-tam)<<endl;
	}	
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int casos, M, a;
string str,resp;
ll fibs[81];
map<ll,ll> id;

// string + fibonacci

void makeFib()
{
	fibs[1] = id[1] = 1;
	fibs[2] = id[2] = 2;
	for(int i = 3; i < 80;i++){
		fibs[i] = fibs[i-1]+fibs[i-2];
		id[fibs[i]] = i;
	}
}

vector<ll> entrada;

int main()
{
	//~ freopen("in","r",stdin);
	
	makeFib();
	scanf(" %d",&casos);
	while(casos--)
	{
		entrada.clear();
		resp.clear();
		
		scanf(" %d",&M);
		ll maximo = 0;
		while(M--)
		{
			scanf("%d",&a);	
			entrada.push_back(a);
			maximo = max(maximo,id[a]);
		}
	
		scanf(" ");
		getline(cin,str);
		
		int j = 0, k = 0;
		resp.resize(maximo,' ');
		for(int i = 0 ; i < (int)str.size() && k < (int)entrada.size() ; i++)
		{
			if(str[i] >= 'A'&& str[i] <= 'Z')
			{
				j = id[entrada[k++]];
				resp[j-1] = str[i];
			}
		}
		cout<<resp<<endl;
	}
}

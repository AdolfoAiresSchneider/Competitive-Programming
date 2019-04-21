#include <bits/stdc++.h>
using namespace std;

vector<int> coeficientes;

int main()
{
	//~ freopen("in","r",stdin);
	int casos,i,a,d,k;
	scanf("%d",&casos);
	while (casos--) 
	{
		coeficientes.clear();
		cin>>i; ++i;
		while (i--) 
		{
			cin>>a;
			coeficientes.push_back(a);
		}
		cin>>d>>k;
		long long sum = 0;
		for (int n = 1 ; n <= k ; n++) 
		{
			sum += n*d;
			if (sum >= k) 
			{
				long long an = 0;
				for (int j = 0 ; j < (int)coeficientes.size() ; ++j ) 
					an += ((long long)coeficientes[j])*((long long)pow((float)n,(float)j));
				cout<<an<<endl;
				break;
			}
		}
	}
}

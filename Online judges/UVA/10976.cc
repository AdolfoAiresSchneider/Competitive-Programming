#include <bits/stdc++.h>
using namespace std;
typedef pair<long long ,long long> ii;

vector<ii> resp;

int main()
{
	//~ freopen("out","w",stdout);
	long long k;
	double x;
	while(cin>>k)
	{
		resp.clear();
		for(long long int i = 2* k; i != k ; i--) //
		{
			x = ((double)k*i)/(i-k)*1.0; // apenas isolei x e verifiquei se era inteiro
			if(x == (int)x) resp.push_back(ii(max((long long)x,i),min((long long)x,i))); 
		}
		sort(resp.rbegin(),resp.rend());
		cout<<resp.size()<<endl;
		for(int i = 0; i < (int)resp.size();i++)
			 printf("1/%lld = 1/%lld + 1/%lld\n", k, resp[i].first, resp[i].second);
	}
}

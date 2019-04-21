#include <bits/stdc++.h>
using namespace std;

int t,n;
int v[1001];
vector<int> vec;
set< vector<int> > resp;

void f(int i, int disp){
	if(disp == 0) resp.insert(vec);
	if(disp < 0 || i >= n) return;
	vec.push_back(v[i]);
	f( i+1 ,disp - v[i]);
	vec.pop_back();
	f(i+1,disp);
}

int main()
{
	while(scanf("%d%d",&t,&n) && t)
	{
		vec.clear();
		resp.clear();
		for(int i = 0 ;  i < n ; i++)
			scanf("%d",&v[i]);
		f(0,t);
		printf("Sums of %d:\n",t);
		vector<int> aux;
		if(resp.size() == 0) puts("NONE");
		else
		{
			for(set< vector<int> >::reverse_iterator it = resp.rbegin(); it != resp.rend(); it++)
			{
				aux = *it;
				for(int i = 0; i < (int)aux.size();i++)
				{
					printf("%d",aux[i]);
					if(i < (int)aux.size()-1) printf("+");
				}
				puts("");
			}
		}
	}
}

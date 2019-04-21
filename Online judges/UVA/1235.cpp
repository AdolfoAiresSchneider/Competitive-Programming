#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

priority_queue<ii> pq;

struct senha
{
	int d1,d2,d3,d4;
	senha(){}
	senha(int a,int b,int c,int d){ d1 = a;d2 = b;d3= c;d4=d; }
	
	int operator + (senha & o){
		int a ,b,c,d;
		a = min(fabs(d1-o.d1),10-fabs(d1-o.d1));
		b = min(fabs(d2-o.d2),10-fabs(d2-o.d2));
		c = min(fabs(d3-o.d3),10-fabs(d3-o.d3));
		d = min(fabs(d4-o.d4),10-fabs(d4-o.d4));
		return a+b+c+d;
	}
};

vector<ii> grafo[500];
vector<senha> senhas;
vector<int> taken;

void process(int vtx)
{
	taken[vtx] = 1;
	for(int i = 0; i <(int)grafo[vtx].size();i++)
	{
		ii v = grafo[vtx][i];
		if(!taken[v.first])
			pq.push(ii(-v.second,-v.first));
	}
}

int main()
{	
	//freopen("in","r",stdin);
	int n,s,a,b,c,d;
	scanf("%d",&n);
	
	while(n--)
	{	
		scanf("%d",&s);
		senhas.push_back(senha(0,0,0,0));
		for(int i = 0; i < s;i++){
			scanf("%1d%1d%1d%1d",&a,&b,&c,&d);
			senhas.push_back(senha(a,b,c,d));
		}
		int aux = 1e9;
		for(int i = 0; i < (int)senhas.size();i++){
			for(int j =i+1 ; j<(int)senhas.size() ; j++ ){
				if(i!=0){
					grafo[i].push_back(ii(j,senhas[i]+senhas[j]));
					grafo[j].push_back(ii(i,senhas[i]+senhas[j]));
				}
				else aux = min(aux,senhas[i]+senhas[j]);
			}
		}
		
		int cost = 0 , u , w ;
		taken.assign(senhas.size()+9,0);
		process(1);
		
		while(!pq.empty())
		{
			ii front = pq.top(); pq.pop();
			u = -front.second;
			w = -front.first;
			if(!taken[u]){
				cost+=w;
				process(u);	
			}
		}
		cout<<cost+aux<<endl;
		for(int i = 0; i < (int)senhas.size()+1;i++) grafo[i].clear();
		senhas.clear();
	}
}

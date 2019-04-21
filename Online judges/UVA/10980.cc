#include<bits/stdc++.h>
using namespace std;

struct Prom
{
	double v;
	int qtd;
	Prom(double a, int b) {v = a; qtd = b;}
};

vector<Prom> pdt;
double dp[200][200];

double f(int i, int disp)
{
	if(disp <= 0) return 0; // coloquei <= para permitir mais que k produtos
	if(i >= (int)pdt.size()) return 2e8;
	double & r = dp[i][disp];
	if(r != -1) return r;
	r = 1e9;
	r = min(r,f(i+1,disp));
	r = min(r,f(i,disp-pdt[i].qtd) + pdt[i].v);
	return r;
}

int main()
{
	//~ freopen("in","r",stdin);
	double unit,a;	
	int m,k,b;
	string str;
	int caso = 1;
	
	while(scanf("%lf%d",&unit,&m) != EOF)
	{
		pdt.clear();
		pdt.push_back(Prom(unit,1));
		for(int i = 0; i < m;i++)
		{
			scanf("%d%lf",&b,&a);
			pdt.push_back(Prom(a,b));
		}
		
		scanf(" ");
		getline(cin,str);
		
		stringstream fluxo(str);
		
		for(int i = 0 ; i < 200;i++)
			for(int j = 0 ; j < 200;j++)
				dp[i][j] = -1;
				
		printf("Case %d:\n",caso++);
		while(fluxo>>k)
		{
			double resp = f(0,k);
			printf("Buy %d for $%.2lf\n",k,resp);
		}
	}
}

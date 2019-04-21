#include <bits/stdc++.h>
using namespace std;

int x[9];
int y[9];

double dp[9][1024];
int N;

double dist(int i, int j)
{
	double dx = x[i] - x[j]; double dy = y[i] - y[j]; return sqrt(dx*dx + dy*dy) + 16;
}

double tsp(int pos, int choice) // menor caminho para passar em todos os vertices 
{
	if(choice == (1 << N) - 1) return 0; // se voltei onde comecei , caso base
	double & r = dp[pos][choice];
	if(r != -1) return r;
	r = 1e9;
	
	for(int i = 0 ; i < N ; ++i)
	{
		if( choice & (1<<i) ) continue; // verifica se foi visitado
		r = min(r,tsp( i , choice | (1<<i)) + dist(pos, i) ); // marca como visitado o v atual!
	}
	return r;
}

void recTsp(int pos, int choice) // reconstroi o tsp
{
	if(choice == (1 << N) - 1) return;
	for(int i = 0 ; i < N; i++)
	{
		if( choice & (1<<i) ) continue;
		if(dp[pos][choice] == tsp(i,choice | (1<<i)) + dist(pos, i) )
		{
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",x[pos],y[pos],x[i],y[i],dist(pos, i));
			recTsp(i,choice | (1<<i));	
		}
	}
	return ;
}

int main()
{
	//~ freopen("in","r",stdin);
	int tc = 1;
	while(scanf("%d", &N), N!=0)
	{
		printf("**********************************************************\n");
		printf("Network #%d\n", tc++);
		
		for(int i=0;i<9;++i)
			for(int j=0;j<1024;++j)
				dp[i][j] = -1;

		for(int i=0;i<N;++i)
			scanf("%d %d", &x[i], &y[i]);
		
		int start = -1;
		double minval = 1e9;
		
		for(int i = 0 ; i < N ; ++i)
		{
			double valor = tsp(i, (1<<i));
			if(valor < minval)
			{
				minval = valor;
				start = i;
			}
		}
		recTsp(start , (1<<start));		
		printf("Number of feet of cable required is %.2lf.\n",minval);
	}
}

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

// Ideia de grafo euleriano -> Apenas soma todas as arestas e converte na em minutos e segundos
// passa por cada aresta apenas uma vez na velociade de limpeza

vector<ii> rx;
vector<ii> ry;

int main()
{
	//~ freopen("in","r",stdin);	
	
	int x1,y1,x2,y2,casos;
	double dist;
	string linha;
		
	scanf("%d",&casos);
	while(casos--)
	{
		scanf("%d%d",&x1,&y1);
		dist = 0;
		scanf(" ");
		while(getline(cin,linha))
		{
			if(linha.empty()) break;
			stringstream fluxo(linha);
			fluxo>>x1>>y1>>x2>>y2;
			dist += 2.0 * hypot(x1-x2,y1-y2);
		}
		
		dist *= 3.0;
		dist = dist/1000.0;
		if((dist - (int)dist) > 0.5 ) dist++;
		cout<<(int)dist/60<<":";
		if((int)dist%60 < 10) cout<<'0';
		cout<<(int)dist%60<<endl;
		if(casos) puts("");
	}
}

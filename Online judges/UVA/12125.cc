#include <bits/stdc++.h>
using namespace std;
// Flow - Quais os vertices que chegam todos os pinguins ?
// Apenas modelar o grafo e rodar o maxflow Dinic alterando a torneira por todos os nós
const int  MAXN = 300;
const int inf = 1e9;

int N,casos,a,b,c,d,S,T,f,mf;
double dist;
vector<int> resp;

struct Point //
{
	int x,y,np,nj;
	Point(int a,int b,int c, int d) { x = a; y = b;np = c; nj = d;}
};

vector<Point> p; // vetor de pontos 

struct edge // arestas para o dinic
{
	int from,to,cap,flow;
	edge(int a, int b,int c, int d){ from = a; to = b; cap = c; flow = d;}
};

bool cmp(edge & a, edge & b){  return a.from < b.from || (a.from == b.from && a.to < b.to); }


struct Dinic
{
    int n,m,s,t;
    vector<edge> edges; // arestas do grafo
    vector<int> G[MAXN]; 
    bool vis[MAXN]; // vetor de visitado
    int d[MAXN];
    int cur[MAXN];
    
    void init(int k)
    {
        n = k;
        for(int  i = 0 ; i <= n ; i++) G[i].clear();
        edges.clear();
    }
    
    void AddEdge(int from , int to , int cap)
    {
        edges.push_back( edge( from , to , cap , 0) );
        edges.push_back( edge(to , from , 0 , 0 ) );
        m = edges.size();
        G[from].push_back( m-2 );
        G[to].push_back( m-1 );
    }
    
    bool BFS()
    {
        memset(vis,0,sizeof vis);
        queue<int> Q; Q.push(s);
        
        d[s] = 0; // vetor de distancia
        vis[s] = 1; // vetor de visitado
        
        while(!Q.empty())
        {
            int x = Q.front(); Q.pop();
            for(int i=0 ; i < (int)G[x].size() ; i++)
            {
                edge & e = edges[G[x][i]];
                
                if( !vis[e.to] && e.cap > e.flow )
                {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t]; // se eu consegui chegar lá
    }
    
    int DFS( int x , int a )
    {
        if( x == t || a == 0 ) return a;
        int flow = 0 , f;
        
        for(int & i = cur[x] ; i < (int)G[x].size() ; i++ )
        {
            edge & e = edges[G[x][i]];
            if( d[x]+1 == d[e.to] && ( f = DFS(e.to , min(a,e.cap-e.flow) ) ) > 0 )
            {
                e.flow += f;
                edges[ G[x][i] ^ 1 ].flow -= f;
                flow += f;
                a -= f;
                if(a == 0) break;
            }
        }
        return flow;
    }
    
    int Maxflow( int s , int t , int need)
    {
        this->s = s;
        this->t = t;
        int flow=0;
        
        while( BFS() ) // enquanto tiver um caminho
        {
            memset(cur,0,sizeof cur);
            flow += DFS(s,inf);
            if(flow > need) return flow;
        }
        return flow;
    }
      
    void ClearFlow()
    {
        for(int i = 0; i < (int)edges.size(); i++) edges[i].flow = 0;
    }
};


int main()
{
	//~ freopen("in","r",stdin);
	
	Dinic Grafo;
	int totalPinguins;
	scanf("%d",&casos);
	
	while(casos--)
	{
		resp.clear(); // limpar vetor de resposta
		p.clear();// limpar os pontos
		totalPinguins = 0; // zerar o total de pinguins
		
		scanf("%d%lf",&N,&dist);
		for(int i = 0; i < N ; i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			p.push_back(Point(a,b,c,d));
			totalPinguins += c;
		}
		
		Grafo.init(2*N+1);
		S = 0;
		
		for(int i = 1; i <= (int)p.size();i++) // split nos nodes com pesos e ligando no S
		{
			Grafo.AddEdge(i*2,i*2+1,p[i-1].nj); // jumps. splitando
			Grafo.AddEdge(S,i*2,p[i-1].np); // pinguins, ligando no source ( S )
		}
		
		for(int i = 1; i <= (int)p.size();i++) 
		{
			for(int j = i+1 ; j <= (int)p.size();j++)	
			{
				double d = hypot(p[i-1].x-p[j-1].x,p[i-1].y-p[j-1].y);
				if(d <= dist)
				{
					Grafo.AddEdge(i*2+1 , 2*j , inf); // Montando as arestas		
					Grafo.AddEdge(j*2+1 , 2*i , inf); // infinito pq nao importa quantos pinguins pulem,
													  // só importa onde pulam e se aguenta
				}
			}
		}	
		
		for(int i = 1 ; i <= N ; i++)
		{
			Grafo.ClearFlow();
			int flow = Grafo.Maxflow(S,i*2,inf);
			if(flow == totalPinguins) resp.push_back(i-1);
		}
		if(resp.size() != 0) 
		{
			for(int i = 0; i < (int)resp.size();i++)
			{ 
				cout<<resp[i];				
				if(i < (int)resp.size()-1) cout<<' ';
			}
			cout<<endl;
		}else puts("-1");
		//~ cout<<"asd"<<endl;
	}
}

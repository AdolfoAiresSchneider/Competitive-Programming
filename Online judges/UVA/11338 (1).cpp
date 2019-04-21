#include <bits/stdc++.h>
using namespace std;

vector<pair<int, double> > grafo[100021];

double dist[1000002];

int used[1000007];


struct Ponto
{
    long long x, y;
    bool operator<(const Ponto &a) const
    {
        if(x != a.x)
            return x < a.x;
        return y < a.y;
    }

    Ponto(long long a, long long b):x(a), y(b)
    {}
    Ponto():x(0), y(0)
    {}

};

Ponto pontos[100021];

void DIKSTRA(double maximo, int inicio, int final, int n) {
    int i;
    for(i = 0; i < n; i++)
    {
        dist[i] = maximo+9999;
        used[i] = 0;
    }
    queue<int> S;
    S.push(inicio);
    dist[inicio] = 0;
    while(!S.empty()) {
        int u = S.front();
        S.pop();
        used[u] = 0;
        for(vector<pair<int, double> >::iterator it = grafo[u].begin(); it != grafo[u].end(); it++) {
            int t = it->first;
            double v = it->second;
            if(dist[t] > dist[u] + v )
            {
                dist[t] = dist[u]+v;
                if(used[t] == 0){
                    S.push(t);
                    used[t] = 1;
                }
            }
        }
    }
    if(dist[final] <= maximo)
        puts("I am lucky!");
    else
        puts("Boom!");
}


int main()
{
    freopen("in","r",stdin);
    freopen("OUTS","w",stdout);
    int w, h, n;
    int i, j;
    long long x, y, a, b;
    double d;
    while(scanf("%d %d", &w, &h) == 2)
    {
        pontos[n++] = Ponto(0, 0);
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%lld.%lld %lld.%lld", &x, &y, &a, &b);
            pontos[i] = Ponto(x*100+y, a*100+b);
        }
        pontos[n++] = Ponto(w*100, h*100);
        sort(pontos, pontos+n);
        for(i = 0; i < n+39; i++) grafo[i].clear();
        for(i = 0; i < n; i++)
        {
            for(j = i+1; j < n; j++)
            {
                if(pontos[j].x - pontos[i].x > 150) break;
                double modulo = sqrt((pontos[j].x-pontos[i].x)*(pontos[j].x-pontos[i].x)+(pontos[j].y-pontos[i].y)*(pontos[j].y-pontos[i].y));
                if(modulo <= 150)
                {
                   grafo[i].push_back(make_pair(j, modulo/100));
                   grafo[j].push_back(make_pair(i, modulo/100));
                }
            }
        }
        scanf("%lf", &d);
        DIKSTRA(d, 0, n-1, n);
    }
}

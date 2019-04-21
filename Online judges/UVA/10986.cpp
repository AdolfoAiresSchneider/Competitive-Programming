#include <bits/stdc++.h>
using namespace std;

#define inf static_cast < int > (1e9)

typedef pair < int, int > ii;
typedef vector < ii > vii;
typedef vector < vii > vvii;

int main()
{

  register int i;
  int test, n, m, s, t, s1, s2, p, size, cont = 0, u, d;
  ii front, v;
  priority_queue <ii, vii, greater<ii> > pq;
  vector < int > dis;
  vvii adj;

  scanf("%d", &test);
  while (test--)
  {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    dis.assign(n, inf);
    adj.assign(n, vii());

    while (m--)
    {
      scanf("%d%d%d", &s1, &s2, &p);
      adj[s1].push_back(ii(s2, p));
      adj[s2].push_back(ii(s1, p));
    }

    dis[s] = 0;
    pq.push(ii(0, s));
    while (!pq.empty())
    {
      front = pq.top();
      pq.pop();
      d = front.first;
      u = front.second;

      if (d > dis[u])
        continue;

      for (i = 0, size = adj[u].size(); i < size; ++i)
      {
        v = adj[u][i];
        if (dis[u] + v.second < dis[v.first])
        {
          dis[v.first] = dis[u] + v.second;
          pq.push(ii(dis[v.first], v.first));
        }
      }
    }

    if (dis[t] != inf)
      printf("Case #%d: %d\n", ++cont, dis[t]);
    else
      printf("Case #%d: unreachable\n", ++cont);
  }

  return 0;
}

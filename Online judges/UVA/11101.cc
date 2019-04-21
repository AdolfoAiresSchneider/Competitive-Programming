#include <bits/stdc++.h>
using namespace std;
// apenas o menor camniho entre dois pontos, BFS

typedef pair<int,int> ii;
typedef pair<pair<int, int>, int> iii;
 
queue<iii> S; 
bool visited[2001][2001];
int shp2[2001][2001];

int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
 
int main() 
{
  //~ freopen("in[","r",stdin);
  int p,x,y;
  while (scanf("%d", &p) && p) 
  {
	memset(visited, 0, sizeof visited);
	memset(shp2, 0, sizeof shp2);
	while(!S.empty())S.pop();
    
    while (p--) 
    {
      scanf("%d%d",&x,&y);
      S.push(iii(ii(x, y), 0));
      visited[x][y] = 1;
    }
    
    scanf("%d", &p);
    while (p--) 
    {
      scanf("%d%d",&x,&y);
      shp2[x][y] = 1;
    }
    
    while (!S.empty()) 
    {
      iii front = S.front(); S.pop();
      
      x = front.first.first;
      y = front.first.second;
           
      if (shp2[x][y]) 
      {
        printf("%d\n", front.second);
        break;
      }
      
      for (int i = 0; i < 4; i++) 
      {
        int xx = x + mx[i];
        int yy = y + my[i];
        if (xx < 0 || xx > 2000 || yy < 0 || yy > 2000 || visited[xx][yy]) continue;
        visited[xx][yy] = true;
        S.push(iii(ii(xx, yy), front.second + 1));
      }
    }
  }
}

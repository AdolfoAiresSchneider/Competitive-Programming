#include <bits/stdc++.h>
using namespace std;

typedef pair< int,int > ii;
typedef pair<double,ii> dii;

struct point 
{
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}	
};

bool cmpx(const point& a, const point& b) {return a.x < b.x;}
bool cmpy(const point& a, const point& b) {return a.y < b.y;}

struct kdtree
{
	point * tree;
	int n;
	
	kdtree(point p[], int n) : tree(new point[n]), n(n) 
	{
		copy(p, p + n, tree);
		build(0, n, 0);
	}
	
	// Knn - k-th nearest neighbor
	vector<point> query(double x, double y, int k = 2)
	{
		perform_query(x, y, k, 0, n, 0);
		vector<point> pts;
		while (!pq.empty()) 	
		{
			pts.push_back(*pq.top().second);
			pq.pop();
		}
		reverse(pts.begin(), pts.end());
		return pts;
	}
	
	bool find(double x, double y, int l, int r, int axis)
	{
		if(l == r) return 0;
		int m = (l+r)/2;
		if( tree[m].x == x && tree[m].y == y) return 1;
		
		if(!axis)
		{
			if(x < tree[m].x)	
				return find(x,y,l,m,!axis);
			return find(x,y,m+1,r,!axis);
		}
		
		if(y < tree[m].y)
			return find(x,y,l,m,!axis);
    return find(x,y,m+1,r,!axis);
		
	}
	
	void build(int L, int R, bool axis) 
	{
		if (L >= R) return;
		int M = (L + R) / 2;	
		nth_element(tree+L , tree+M , tree+R, axis ? cmpx : cmpy );
		build(L, M, !axis), build(M+1, R, !axis);
	}
	
	priority_queue<pair< double, point* > > pq;
	void perform_query(double x, double y, int k, int L, int R, bool axis) 
	{
		if (L >= R) return;
		int M = (L + R) / 2;
		
		double dx = x - tree[M].x;
		double dy = y - tree[M].y;
		
		double delta = axis ? dx : dy;
		double dist = dx * dx + dy * dy;
		
		if ((int)pq.size() < k || dist < pq.top().first) 
		{
			pq.push({dist, &tree[M]});
			if ((int)pq.size() > k) pq.pop();
		}
		
		int nearL = L, nearR = M, farL = M + 1, farR = R;
		
		if (delta > 0) 
			swap(nearL, farL), swap(nearR, farR);
		
		perform_query(x, y, k, nearL, nearR, !axis);

		if ((int)pq.size() < k || delta * delta < pq.top().first)
			perform_query(x, y, k, farL, farR, !axis);
	}
};

int main()
{
	//~ freopen("in","r",stdin);
	
	int N,C,K;
	double D;
    int p[2],resp;
    
    while(scanf("%d%d%d%lf",&N,&C,&K,&D) == 4)
    {  
		point pontos[N+3];
        resp = 0;
       
        for(int i = 0; i < N; i++)
        {
            scanf("%d%d",&p[0],&p[1]);
            pontos[i] = point(p[0],p[1]);
        }
       
		kdtree tree(pontos,N); // Building
		
		if(N < K)
			K = N;
		
      while(C--)
      {
        scanf("%d%d",&p[0],&p[1]);
        double soma = 0;
        vector<point> dists = tree.query(p[0],p[1],K);
        
        if( tree.find(p[0],p[1],0,N,0) )
          continue;
        
        for(size_t i = 0 ; i < dists.size();i++)
          soma += hypot(p[0]-dists[i].x,p[1] - dists[i].y);
            
        if(soma >= D )
          resp++;
      }       
      printf("%d\n",resp);              
    }
}

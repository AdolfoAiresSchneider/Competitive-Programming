#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define INF 1e9
#define PI  3.141592653589793

#define vec(a,b) point(b.x-a.x,b.y-a.y)

//  Pontos  ---------------------------------------------------------------------------------------------
struct point
{
    double x , y ;
    point(double x , double y ): x(x), y(y){}
    point(){}
    point operator - (point  p){ return point(x - p.x , y - p.y ); }
	point operator * (double c){ return point(x * c, y * c ); }
	point operator + (point  p){ return point(x + p.x, y + p.y); }
	point operator / (double b){ return point(x / b, y / b); }
};

double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

double dot(point a, point b){
	return a.x*b.x +  b.y*a.y;
}

double cross (point A, point B, point C){
	// AB X AC	
	return (B.y - A.y) * (C.x - B.x) -(B.x - A.x) * (C.y - B.y);
}

bool ccw(point a, point b, point c){
	return cross(a,b,c) < 0;
}

double angle(point a, point o, point b)
{
    return acos(dot(vec(a,o), vec(b,o)) / (dist(a,o)*dist(o,b)));
}

//  Line e segment ---------------------------------------------------------------------------------------------
struct line
{
    double a , b , c ;
    line(point p , point q)
    {
		a = p.y - q.y;
		b = q.x - p.x;
		c = -a * p.x - b * p.y;
    } 
    line(int a,int b, int c) : a(a), b(b), c(c){}
    line(){}
};

line ortoLine(line l, point p, line per = line()) 
{
    per.a = -l.b;  
    per.b = l.a; 
    per.c = -per.a * p.x - per.b * p.y;
    return per;
}

// trata se forem as mesmas linhas
bool intersection( line A1, line B1, point & p , bool & sameLine )
{
	double det = A1.a * B1.b - A1.b * B1.a;
	if( fabs( det - 0 ) < EPS ) 
	{
        if( (A1.c - A1.a) / A1.b == (B1.c - B1.a)/B1.b ) sameLine = true;
        return false;
	}
	p.x = ( A1.b * B1.c - B1.b * A1.c ) / det;
	p.y = ( A1.c * B1.a - B1.c * A1.a ) / det;
	return true;
}

// standard
bool intersection( line A1, line B1, point & p)
{
	double det = A1.a * B1.b - A1.b * B1.a;
	if( fabs( det - 0 ) < EPS )	return false;
	p.x = ( A1.b * B1.c - B1.b * A1.c ) / det;
	p.y = ( A1.c * B1.a - B1.c * A1.a ) / det;
	return true;
}

bool onSegment (point A, point B, point C)
{
	//AB , AC
    if (C.x <= max(A.x, B.x) && C.x >= min(A.x, B.x) && 
		C.y <= max(A.y, B.y) && C.y >= min(A.y, B.y))
       return true;
    return false;
}

// verifica se os segmentos se intersectam !
bool doSegIntersect (point A1, point A2, point B1, point B2)
{	
	int o1 = cross(A1,A2,B1), o2 = cross(A1,A2,B2);
	int o3 = cross(B1,B2,A1), o4 = cross(B1,B2,A2);
	
	// orientações diferentes, se intersectam
	if(o1 != o2 || o4 != o3)
		return true;
	
	if(!o1 && onSegment(A1,A2,B1)) return true;
	if(!o2 && onSegment(A1,A2,B2)) return true;
	if(!o3 && onSegment(B1,B2,A1)) return true;
	if(!o4 && onSegment(B1,B2,A2)) return true;
	return false;
}


//  Circle ---------------------------------------------------------------------------------------------
struct circle
{
	point center;
	double r;
	
	circle(){}
	circle(point center, double r) : center(center), r(r){}
	
	circle(point & p1, point & p2, point & p3)
	{
		line l1 = ortoLine(line(p1,p2),(p1+p2)/2.);
		line l2 = ortoLine(line(p2,p3),(p2+p3)/2.);
		intersection(l1,l2,center);
		r = dist(center,p1);
	}
};

// verifica se existe um circulo em que os pontos estejam na borda da circunferencia
bool circle2PtsRad(point p1, point p2, double r, point  & c)
{
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) +  (p1.y - p2.y) * (p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  return true; 
}

//  pgon  ---------------------------------------------------------------------------------------------

// asumindo que o iltimo é igual ao primniero
bool inpgon(point pt, vector<point> & P) 
{
	if ((int)P.size() == 0) return false;
	double sum = 0;
	for (size_t i = 0; i < P.size()-1; i++)
	{
		if (ccw(pt, P[i], P[i+1]))
		sum += angle(P[i], pt, P[i+1]);
		else sum -= angle(P[i], pt, P[i+1]); 
		
	} 
	return fabs(fabs(sum) - 2*PI) < EPS;
}

double pgonArea(vector<point> & p)
{
	double area = 0;
	for(int i = 1; i+1 < (int)p.size(); i++)
		area += cross(p[0],p[i],p[i+1]);
	return area;
}

int main()
{
	vector<point> p;
	//~ freopen("IN","r",stdin);
	//~ freopen("out","w",stdout);
	
	
	int c = 0;
	for(int i = 0; i < 4; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		p.push_back(point(x,y));
	}
	
	int x,y;
	scanf("%d%d",&x,&y);
	
	for(int i = 0; i < (int)p.size(); i++){
		for(int j = i+1; j < (int)p.size(); j++){
			for(int k = j+1; k < 4 ; k++)
			{
				double q = cross(p[i],p[j],p[k]);
				if(q != 0){
					c = 1;
					goto A;
				}
			}
		}
	}
	
	A: p.push_back(p[0]);
	if(!c)
	{
		printf (" O>\n<|\n/ >\n");
		return 0;
	}
	
	
	for(int i = 0; i < 4; i++)
	{
		if(cross(point(x,y),p[i],p[i+1]) == 0)
		{
			printf ("\\O/\n |\n/ \\\n");
			return 0;
		}
	}
	

	if(inpgon(point(x,y),p)) printf ("\\O/\n |\n/ \\\n");
	else printf (" O>\n<|\n/ >\n");

}

#include <bits/stdc++.h> 
using namespace std;

int px[8];
int p[8];

bool val(int r, int c)
{
	for(int i = 0 ; i < r ; i++)
	{
		if(c == p[i]) return false;
		if(abs(r-i) == abs(c - p[i])) return false;
	}
	return true;
}

int f(int q)
{
	if(q == 8) return 0;
	int resp = 1e9;
	for(int i = 0 ; i < 8; i++)
	{
		if( val(q,i) )
		{ 
			p[q] = i; // LINHA ATUAL
			resp = min(resp , i == px[q] ? f(q + 1) : 1 + f(q + 1));
		}
	}
	return resp;
}

int main()
{
	//~ freopen("in","r",stdin);
	//~ freopen("iout","w",stdout);
	
	int casos = 1;
	while(scanf("%d",&px[0]) != EOF)	
	{
		px[0]--; p[0] = px[0];
		for(int i = 1; i < 8; i++)
		{
			scanf("%d",&px[i]);	
			px[i]--; p[i] = px[i];
		}
		printf("Case %d: %d\n",casos++,f(0));		
	}
}

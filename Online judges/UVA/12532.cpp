#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000009

int valores[MAXN];
int st[4*MAXN];

void update(int no, int l, int r, int posic, int valor)
{
	
	if( l > posic || posic > r ) return; // fora do intervalo
	
	if(l == r && r == posic)
	{ 
		st[no] = valor;
		return;
	}
	
	int noR = 2*no+1;
	int noL = 2*no;
	int mid= (l+r)/2;
	
	update(noL,l,mid,posic,valor);
	update(noR,mid+1,r,posic,valor);
	
	st[no] = st[noR] * st[noL];
}

int query(int no, int l, int r, int i , int j)
{
	if( i > r || j < l) return 1 ;
	
	if(l >= i && r <= j)  return st[no];
	
	int noR = 2*no+1;
	int noL = 2*no;
	int mid= (l+r)/2;
	
	int vR = query(noR,mid+1,r,i,j);
	int vL = query(noL,l,mid,i,j);
	
	return vR*vL;
}

int main()
{
	int n,k;

	while(scanf("%d%d",&n,&k) != EOF)
	{
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%d",&valores[i]);
			if(valores[i] == 0)
				update(1 , 0 , n-1 , i , 0 );
			else
			{
				if( valores[i] > 0 ) update( 1 , 0 , n-1 , i , 1 );
				else update( 1 , 0 , n-1 , i ,-1 );
			}
		}
		
		
		char a;
		int b,c;
		
		while(k--)
		{
			scanf(" %c%d%d",&a, &b, &c);
			if(a == 'C')
			{
				if(c == 0) update( 1 , 0 , n-1 , b-1 , 0 );
				else
				{
					if( c > 0 ) update(1 , 0 , n-1 , b-1 ,1 );
					else update(1,0,n-1, b-1 , -1);
				}
			}
			else
			{
				int aux = query( 1 , 0 , n-1 , b-1 , c-1);	
				if(aux > 0)cout<<'+';	
				if(aux < 0) cout<<'-';
				if(!aux) cout<<'0';				
			}
		}
		cout<<endl;
	}
}

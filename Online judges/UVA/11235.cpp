#include <bits/stdc++.h>
using namespace std;
#define MAXN 200009
#define INF 1e9

struct range
{
	int ii,jj;
	range(){}
	range(int i, int j){ ii = i; jj = j ;}
};

int valores[MAXN];
int freq[MAXN];
range intervalo[MAXN];
map<int,int> qtd;
int st[4*MAXN];


void update(int no, int l, int r, int posic, int valor)
{
	if( posic < l || posic > r) return; // fora do intervalo
	
	if(l == r ) // folha
	{
		st[no] = valor;
		return;
	}
	int noL = 2*no;
	int noR = 2*no+1;	
	int mid = (l+r)/2;
	
	update(noL,l,mid,posic,valor);
	update(noR,mid+1,r,posic,valor);
	
	st[no] = max(st[noR],st[noL]);
}

int query(int no, int l,int r,int i, int j)
{
	if( i > r || j < l ) return -INF;
	
	if( i <= l && r <= j ) return st[no];
	
	int noL = 2*no;
	int noR = 2*no+1;
	int mid = (l+r)/2;
	
	int VL = query(noL,l,mid,i,j);
	int VR = query(noR,mid+1,r,i,j);
	
	
	return max(VL,VR);
}



int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n,m,a,b;
	while(scanf("%d",&n)&& n)
	{
		scanf("%d",&m);
		for(int i = 0; i < n;i++){
			scanf("%d",&valores[i]);
			valores[i] += 100000;
			qtd[valores[i]]++;						
		}
		
		for(int i = 0; i < n;i++)
			freq[i] = qtd[valores[i]];
			
			
		for(int i = 0;i<n;i++){
			int j = i;
			while(valores[j+1] == valores[j]) j++;
			intervalo[valores[i]] = range(i,j);
			i = j;
		}
		
		for(int i = 0; i < n; i++) update(1,0,n-1,i,freq[i]);
		
		while(m--)
		{
			scanf("%d %d",&a,&b);
			a--;
			b--;
		
			if(valores[a] == valores[b]) cout<<(b-a)+1<<endl;
			else
			{
				int aa=0,bb=0,cc=0;
				if(intervalo[valores[a]].ii < (a) )
				{ 
					aa = (intervalo[valores[a]].jj - (a) ) + 1;
					a = intervalo[valores[a]].jj + 1;
				}
				if(intervalo[valores[b]].jj > b) 
				{
					bb = ( (b) - intervalo[valores[b]].ii) + 1;
					b = (intervalo[valores[b]].ii) - 1;
				}
				if(a <= b ) cc = query(1,0,n-1,a,b);
				cout<<max(aa,max(bb,cc))<<endl;
			}
		}
		qtd.clear();	
		memset(freq,0,sizeof freq);
	}
}

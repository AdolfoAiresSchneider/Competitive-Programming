#include <bits/stdc++.h>
using namespace std;
 
#define gcd __gcd
#define maxn 40001
int a,b,c;
 
int f(int b1, int b2, int x, int y)
{
	int ans = 0;
	while(b1 != c && b2 != c)
	{
		if(b1 == 0)
			b1 = x;
		else 
		{
			if(b2 == y) b2 = 0;
			else
			{
				b2 += b1;
				b1 = 0;
				
				if(b2 > y)
				{
					b1 = b2 - y;
					b2 = y; 
				}
			}
		}
		ans++;
	}
	return ans;
} 
 
int main()
{
	int casos;
	
	cin>>casos;
	
	while(casos--)
	{
		cin>>a>>b>>c;
		if((c > a && c > b) || c % gcd(a,b))
			cout<<-1<<endl;
		else cout<<min(f(0,0,a,b),f(0,0,b,a))<<endl;
	}
}

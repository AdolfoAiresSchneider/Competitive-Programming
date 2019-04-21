
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 
int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		double a,b,c,d;
		cin>>a>>b>>c>>d;
		double s = (a+b+c+d)/2;
		double r = sqrt((s-a)*(s-b)*(s-c)*(s-d));
		printf("%.2lf\n",r);
	}
}
 

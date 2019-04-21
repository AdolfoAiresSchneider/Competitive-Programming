#include <bits/stdc++.h>
using namespace std;

long long int f[10000];
long long int f2[10000];

long long int fib1(long long int n)
{
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(f[n]>=0) return f[n];
	return f[n] = (fib1(n-1) + fib1(n-2))+1;	
}

long long int fib2(long long int n)
{
	if(n == 0) return 1;
	if(n == 1) return 2;
	if(f2[n]>=0) return f2[n];
	return f2[n] = (fib2(n-1) + fib2(n-2))+1;	
}


int main()
{
	long long int n;
	memset(f,-1,sizeof(f));
	memset(f2,-1,sizeof(f));
	f[1] = 2;f[2] = 2;f[3] = 4;f2[1] = 2;f2[2] = 4;f2[3] = 7;
	while(cin>>n &&n!=-1)
	{
			cout<<fib1(n)<<' '<<fib2(n)<<endl;
	}
}

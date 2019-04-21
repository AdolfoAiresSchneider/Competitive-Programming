#include <bits/stdc++.h>
using namespace std;
int valores[10009];

int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		for(int i = 0;i<n;i++) scanf("%d",&valores[i]);
		
		int sum = 0,ans = 0;
		
		for(int i = 0; i < n;i++)
		{
			sum += valores[i];
			ans = max(sum,ans);
			if(sum < 0) sum = 0;
		}
		
		if(ans > 0) printf("The maximum winning streak is %d.\n",ans);
		else printf("Losing streak.\n");
	}	
}

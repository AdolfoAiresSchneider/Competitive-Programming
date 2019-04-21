#include<bits/stdc++.h>
using namespace std;

#define mod 23102009

char s1[1001];
int mem[1001][1001];
int dp2[1001][1001];
char s2[1001];

// calculates the number of distincts lcs
int cnt(int i,int j)
{
	if(i <= 0 || j <= 0 ) 
    return 1;
  int & r = dp2[i][j];

	if(r != -1) 
    return r;
	
  if(s1[i] == s2[j]) 
    return r = cnt(i-1,j-1);
  
	if(mem[i][j-1] != mem[i-1][j])
	{
			if(mem[i-1][j] > mem[i][j-1]) 
        return r = cnt(i-1,j);
			return r = cnt(i,j-1);
	}
  
	if(mem[i-1][j-1] == mem[i-1][j]) 
    return r = ( (cnt(i-1,j)%mod + cnt(i,j-1)%mod - cnt(i-1,j-1))%mod + mod )%mod;	
	return  r = (cnt(i-1,j)+cnt(i,j-1))%mod;
}
 
 
int main()
{
	///freopen("in","r",stdin);
	int n,r,l;
	register int i,j;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s%s",&(s1[1]),&(s2[1]));
		memset(dp2,-1,sizeof(dp2)); 
		memset(mem,0,sizeof(mem));

		s1[0] = '#'; s2[0]='$';

		r = strlen(s1)-1;
		l = strlen(s2)-1;
		
		for(i=1;i<=r;++i)
			for(j=1;j<=l;++j)
				if(s1[i] == s2[j]) 
          mem[i][j] = mem[i-1][j-1]+1;
				else mem[i][j] = max(mem[i][j-1], mem[i-1][j]);
				
		printf("%d %d\n",mem[r][l],cnt(r,l));
	}
}

#include <bits/stdc++.h>
using namespace std;
 

const char *a[] = {"", "1", "22", "333", "4444", 
	"55555", "666666", "7777777", "88888888",
	 "999999999"};
 
int main()
{
	int n,m,t,i,k;
    scanf("%u", &n);
 
    while(n--)
    {
        scanf("%u%u", &m, &t);
 
        while(t--)
        {
            for(i = 1; i < m; ++i) printf("%s\n", a[i]);
 
            for(k = i; k; --k) printf("%s\n", a[k]);
 
            if(t || n) printf("\n");
        }
    }
}

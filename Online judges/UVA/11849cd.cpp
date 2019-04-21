#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <set>
using namespace std;


int main()
{
    long long int aux,m,n;
    int conta=0;

    while(scanf("%lld %lld",&m,&n),m!=0 || n!=0 )
    {
        conta=0;
        map<long long int,long long int> cd;

        while(m--)
        {
            scanf("%lld",&aux);
            cd[aux] = 1;
        }
        while(n--)
        {
            scanf("%lld",&aux);
            cd[aux] = cd[aux]+1;

            if(cd[aux] == 2)
                conta++;
        }
        printf("%lld\n",conta);
    }
}


#include <iostream>
#include <map>
#include <queue>
#include <cstdio>
#include <string>
using namespace std;


class compare {
    public :
bool operator ()( const pair<int,int> &A , const pair<int,int> &B )
{
       if ( A.first < B.first )
           return false ;
           else if ( A.first > B.first )
           return true ;
           else {
                  if (A.second < B.second )
                      return false ;
                  else
                      return true ;
           }
}
};


int main()
{
   // priority_queue<f, vector<f>, op > fluxo;
    priority_queue<pair <int, int> , vector<pair<int, int> >, compare  > fluxo;
    int reg;
    char p[20];
    map<int,int> mapa;
    int a,b;
    while(scanf(" %s",p), p[0]!='#')
    {
		pair<int,int> par;
        scanf("%d",&a);
        scanf("%d",&b);
        mapa[a] = b;
        par.first=b;
        par.second=a;
        fluxo.push(par);
    }
    scanf("%d",&reg);
    while(reg--)
    {
        pair<int,int> print = fluxo.top();
        fluxo.pop();
        printf("%d\n",print.second);
        print.first += mapa[print.second];
        fluxo.push(print);
    }
}

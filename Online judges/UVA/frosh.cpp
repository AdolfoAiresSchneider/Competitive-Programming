#include <cstdio>
#include <string.h>
#include <cstring>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <set>
using namespace std;
int main()
{
   int frosh;
   int aux;
   int qtd;
   int rep;
   while( scanf("%d",&frosh),frosh!=0)
   {
        map<set<int>,int> mapa;
        set<int> seta;
        qtd=frosh;
        rep=0;
        while(frosh--)
        {
            for(int i=0;i<5;i++)
            {
                scanf("%d",&aux);
                seta.insert(aux);
            }
            mapa[seta]++;
            if(mapa[seta]>rep)
                rep = mapa[seta];
            seta.clear();
        }
        map<set<int>,int>::iterator it=mapa.begin();
        int s = 0;
        for(it=mapa.begin(); it!=mapa.end() ;it++)
            if(it->second == rep)
                s = s + it->second;
        printf("%d\n",s);
   }
}

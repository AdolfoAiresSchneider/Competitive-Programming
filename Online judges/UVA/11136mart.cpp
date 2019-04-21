#include <set>
#include <iostream>
using namespace std;
#include <cstdio>
#include <map>
long int dias,contas,k,valor,maior,menor;
set<long int> urna;
set<long int>::iterator it;
set<long int>::reverse_iterator rt;
map<long int,long int> mapa;
int main()
{
    while(scanf("%ld",&dias),dias!=0)
    {
        urna.clear();
        mapa.clear();
        valor=0;
        while(dias--)
        {
            scanf("%ld",&k);
            while(k--)
            {
                scanf("%ld",&contas);
                urna.insert(contas);
                mapa[contas]++;
            }
            it=urna.begin();///menor
            rt=urna.rbegin();//maior
            valor += *rt - *it;
            maior = -1 +mapa[*rt]--;
            menor = -1 + mapa[*it]--;
            if(maior == 0 )
                urna.erase(*rt);
            if(menor == 0 )
                urna.erase(it);
        }
        printf("%ld\n",valor);
    }
}

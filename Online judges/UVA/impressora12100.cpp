#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

inline int verificapriori(int * vet, int prioridade)
{
    for(int i = 0;i<9;i++)
        if(prioridade < i+1 && vet[i] > 0)
            return 1;
    return -1;
}

int main()
{
    int n, m, pt,posic,i,tempo;
    scanf("%d",&n);
    while(n--)
    {
        vector<int> vet;
        int vet2[10]{0,0,0,0,0,0,0,0,0,0};
        tempo =0;
        scanf("%d",&m);
        scanf("%d",&posic);
        for(i=0;i<m;i++)
        {
            scanf("%d",&pt);
            vet.push_back((i!=posic)? pt:pt+10);
            vet2[pt-1]++;
        }
        while(true)
        {
            m = vet.front();
            if(verificapriori(vet2,( (m-10)>0) ? m-10:m) < 0)
                if(m>10)
                {
                    tempo++;
                    break;
                }
                else
                {
                    tempo++;
                    vet2[m-1]--;
                    vet.erase(vet.begin());
                }
            else
            {
                vet.erase(vet.begin());
                vet.push_back(m);
            }
        }
        printf("%d\n",tempo);
    }
}


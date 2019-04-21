#include <iostream>
#include <map>
using namespace std;

int casos, flocos, x, tamanho;
int tatual, comeco,i;

int main()
{
    scanf("%d",&casos);
    
    while(casos--)
    {
        comeco = 0;
        scanf("%d",&flocos);
        tatual = 0;
        map<int, int> indice;
        tamanho = 0;

        for(i=1; i<=flocos; i++)
        {
            scanf("%d",&x);
            int ultimaposic = indice[x];
            if(ultimaposic != 0)
            {
                if(comeco<ultimaposic)
                    comeco = ultimaposic;
                tatual = i-1-comeco;
            }
            
            indice[x] = i;
            
            tatual++;

            if(tatual>tamanho)
                tamanho = tatual;
        }
        
        printf("%d\n",tamanho);
    }
}

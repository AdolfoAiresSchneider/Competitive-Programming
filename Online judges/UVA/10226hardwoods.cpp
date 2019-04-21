#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
int casos,qtdav;
priority_queue<string,vector<string>,greater<string> > lista;
map<string,int> mapa;

int main()
{
    char name[35];
    scanf("%d\n\n",&casos);
    while(casos--)
    {
        qtdav=0;
        mapa.clear();
        while (gets(name))
        {
            if (strlen(name) == 0)
                break;
            qtdav++;
            if(mapa[name] == 0)
                lista.push(name);
            mapa[name]++;
        }
        while(!lista.empty())
        {
            string t;
            t=lista.top();
            lista.pop();
            float pc  = 100.0/qtdav;
            cout<<t<<" ";
            printf("%.4lf\n",(mapa[t]*1.0)*pc);
        }
        if(casos>0)
            printf("\n");
    }
}


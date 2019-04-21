#include <iostream>
using namespace std;
#include <queue>
#include <cstdio>
#include <vector>
#include <set>

int qtd,n,aux,i,j;

int main()
{
    while(scanf("%d",&qtd),qtd != 0 )
    {
        priority_queue<int, vector<int>, greater<int> > fila;
        while(qtd--)
        {
            scanf("%d",&n);
            fila.push(n);
        }
        aux=0;
        while(fila.size()!=2)
        {
            i=fila.top();
            fila.pop();
            i = i+ fila.top();
            aux= aux+i;
            fila.pop();
            fila.push(i);
        }
        i=fila.top();
        fila.pop();
        i = i+ fila.top();

        cout<< i + aux<<endl;


    }
    return 0;
}

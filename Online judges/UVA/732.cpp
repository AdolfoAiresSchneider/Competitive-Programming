#include <iostream>
using namespace std;
#include <stack>
#include <cstdio>
#include <vector>

vector<int> P;
stack<char> pilha;
string Letra1,Letra2;

void busca(int x, int y)
{
        if(x==Letra1.size() && y == Letra2.size())
        {

            for(int i=0;i<P.size();i++)
            {

                if(P[i] == 1)
                    cout<<'i'<<' ';
                else
                {
                    cout<<'o';
                    if(i!=P.size()-1)
                        cout<<' ';
                }
            }
            cout<<endl; return;
        }

        if( x < Letra1.size())
        {
            P.push_back(1);
            pilha.push(Letra1[x]);

            busca(x+1,y);
            P.pop_back(); pilha.pop();
        }

        if(!pilha.empty() && y<Letra2.size() && pilha.top() == Letra2[y])
        {
            char aux = pilha.top();
            P.push_back(0);
            pilha.pop();
            busca(x,y+1);
            pilha.push(aux); P.pop_back();
        }
}

int main()
{
    while(cin>>Letra1>>Letra2)
    {

        P.clear();
        printf("[\n");
        busca(0,0);
        printf("]\n");
    }

}


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include <stack>   


int aux3;

int qtd;
int c;


inline void criarpilha(int i, stack<int> * cartas)
{
	for(int j = i; j>0;j--)
	{
		cartas->push(j);	
	}
	
}

inline void imprimir(stack<int> * cartas,stack<int> * aux)
{
	int c = aux->size(),i;
	   
	c= aux->size();
	for(int i = 0; i < c;i++)
	{
		cartas->push(aux->top());
		aux->pop();
	}
	for(i =0;i<c-1;i++)
	{
			printf(" %d,",cartas->top());
			cartas->pop();
	}
	
	printf(" %d",cartas->top());
			
}

int main()
{
	while(scanf(" %d",&qtd), qtd!=0)
	{
		stack<int> cartas,aux,aux2;
		criarpilha(qtd,&cartas);
		c= cartas.size();
		while(c!= 1)
		{
				
				aux.push(cartas.top());
				cartas.pop();
				aux3 = cartas.top();
				cartas.pop();
				c= cartas.size();
				for(int i = 0; i < c;i++)
				{
					aux2.push(cartas.top());
					cartas.pop();
				}
			    cartas.push(aux3);
			    c= aux2.size();
			    for(int i = 0; i < c;i++)
				{
					cartas.push(aux2.top());
					aux2.pop();
				}
				c= cartas.size();
		}
		if(qtd==1)
		{	
				c=1;
				printf("Discarded cards:");
				printf("\nRemaining card: %d\n",c);
		}
		else
		{
			
			printf("Discarded cards:");
			int c =cartas.top();
			imprimir(&cartas,&aux);
			printf("\nRemaining card: %d\n",c);
		}
	}
	
return 0;	
}






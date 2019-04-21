#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include <stack>  
	int ordem[1002];
	int permut,i,j;
	
void ler()
{
	for(int i=0;i<permut;i++)
		{
			 scanf(" %d",&ordem[i] ); 
			 if(ordem[i]==0)
				return;
	   }
}
 
int main()
{
	while(scanf("%d",&permut), permut!=0)
	{		
			while(ler(), ordem[0]!= 0 )
			{   
				stack<int> pilha,entrada;
				j=0;
				for(i = permut ; i>0 ; i--)
				{
					entrada.push(i);
				}
				while(entrada.size() != 0)
				{
					int c = pilha.size();
					if(c==0)
					{
						if(entrada.top() == (ordem[j]))
						{
							j++;
							entrada.pop();
						}
						else
						{
							pilha.push(entrada.top());
							entrada.pop();
						}
					}
					else
					{
						if(entrada.top() == (ordem[j]))
						{
							j++;
							entrada.pop();
						}
						else
						{
							if(pilha.top() == (ordem[j]))
							{
								j++;
								pilha.pop();
							}
							else
							{
								pilha.push(entrada.top());
								entrada.pop();
							}	
						}		
					}
				}
				while(pilha.size()!= 0 && pilha.top() == (ordem[j]))
				{	
					pilha.pop();
					j++;
				}
				int c = pilha.size();
				if(c==0)
					printf("Yes\n");
				else
					printf("No\n");	
			
			}
			cout<<endl;
	}
	return 0;
}






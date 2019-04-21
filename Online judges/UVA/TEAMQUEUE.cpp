#include<cstdio>
#include<queue>
#include<map>
using namespace std;
#include<iostream>


int main()
{
	
	int cenario = 0;
	int i,n,x,t;
	char COMANDO[10];
	while(scanf("%d", &t) == 1 && t)
	{
		map<int, int> team;// uso o map apenas para saber qual o time da pessoa
		printf("Scenario #%d\n", ++cenario);
		
		for( i = 0; i < t; i++)
		{
			scanf("%d", &n);
			
			while(n)
			{
				scanf("%d", &x);
				n--;
				team[x] = i;//UTILIZA O VALOR COMO CHAVE, SE TIVER O MESMO I É PQ PERTENCE AO MESMO TIME ---MAPEANDO----
			}
		}
		
		queue<int> fila2[1039],fila ;
		
		while(true)
		{
			scanf("%s", COMANDO);
		
			if(COMANDO[0] == 'S') 
				break;
				
			else 
			{
				if(COMANDO[0] == 'E')
				{
					scanf("%d", &x);
					
					t = team[x];// Retorna a qual time o numero pertence
					
					if(fila2[t].empty())/// Se nao existir mais o time na fila, ou nunca tenha entrado,  apenas colcoca
						fila.push(t);// Adiciona uma equipe caso nao tenha na fila
						
					fila2[t].push(x);/// Coloca no final de uma fila do vetor de filas					
				}
				else 
				{
					if(COMANDO[0] == 'D')
					{						
						int t = fila.front();//t recebe a cabeça da fila 1, ou seja o time que tem que tirar
						
						printf("%d\n", fila2[t].front());
						
						fila2[t].pop();
						
						if(fila2[t].empty()) ///so tira da fila principal uma equipe se acabar as equipes na fila
							fila.pop();//tira da fila principal caso nao exista mais da equipe na fila
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}	

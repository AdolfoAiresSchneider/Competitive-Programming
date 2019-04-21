#include <iostream>
		using namespace std;
		#include <stdio.h>
		int a[100005];
		int pai(int ende)//encontra o pai e otimiza para ter o mesmo pai
		{
			if( a[ende] == ende)
				return ende;
			return a[ende]=pai(a[ende]);
		}
		int main()
		{	
			int k,i,d,p,q,l,m;
			char b;
			scanf(" %d%d",&d,&k);
			for(i=1;i<=d;i++)
				a[i]=i;
			for(i=1;i<=k;i++)
			{
				scanf(" %c%d%d",&b,&p,&q);//le o char e os dois endereços
				if(b =='F')//faser uma fusao
				{
					l=pai(p);//acha o banco  pai do banco p
					m=pai(q);	//acha o banco pai do banco q
						a[l]=m;///nao meche nos bancos em si, apenas nos bancos pais, movendo a arvore para um banco apenas, assim se 
							   ///a fusão ocorrer , os bancos da fusao passaram a ter o mesmo pai, logo sendo o mesmo banco
				}
				else//fazer uma consulta, toda vez o grafo e otimizado
				{
					if( pai(p) == pai(q))// se os pais forem iguais, siginifica que e o mesmo banco
						printf("S\n");
					else
						printf("N\n");
				}
			}
		return 0;
		}

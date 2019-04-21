#include <iostream>
using namespace std;
#include <cstdio>
#include <string.h>
#include <list>



 
int main()
{
	int i;
	list<char> texto;
	string digitado;
	list<char>::iterator itr;
	
	while(getline(cin,digitado))
	{
		texto.clear();
		itr = texto.begin();
		int c = digitado.size();
		for(i =0 ; i < c ; i++)
		{		
			if(digitado[i] == '[')
			{
				itr=texto.begin();
			}
			else
			{
				if(digitado[i] == ']')
				{
					itr = texto.end();
				}
				else
				{
					texto.insert(itr,digitado[i]);
				}
			}
			
		}
		
		c = texto.size();
		for(int i=0;i< c;i++)
		{
			printf("%c",texto.front());
			texto.pop_front();
		}
		printf("\n");
		
	}
	
	

}

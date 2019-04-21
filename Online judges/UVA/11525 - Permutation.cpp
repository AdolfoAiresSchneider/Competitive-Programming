#include <iostream>
using namespace std;
#include <cstdio>
#include <stack>
#include <vector>
int main()
{
	
	
	vector<int> vect;
	int k;
	int i,j;
	scanf("%d",&j);
	
	while(j--)
	{
		scanf("%d",&k);	
		for(int c = 1;c<=k;c++)
			vect.push_back(c);
		cout<<vect[3];
			
		while(k--)
		{
			scanf(" %d",&i);
			printf("%d%s",vect[i],(k != 0 ) ? " ":"");		
			vect.erase(vect.begin()+i);
		}
		cout<<"\n";
	}
}

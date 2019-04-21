
using namespace std;
#include <iostream>
#include <stack>
#include <vector>


int i,m;

int main()
{
    while(true)
    {
		vector< stack<string> > vet(52);
		string aux;
		vector< stack<string>>::iterator itr;
		
        for(i=0;i<52;i++)
        {
            cin>>aux;
            if(aux[0] == '#')
                break;
            vet[i].push(aux);
        }
          if(aux[0] == '#')
                break;
		
		itr = vet.begin();
		i=0;
		while(itr!=vet.end())
		{
				if(i-3 >= 0 && (vet[i].top()[0] == vet[i-3].top()[0] || vet[i].top()[1] == vet[i-3].top()[1]) )
				{
					vet[i-3].push(vet[i].top());
					vet[i].pop();
					if(vet[i].empty())
					   vet.erase(vet.begin()+i);
					i = i-3;
					itr=vet.begin()+i;
				}
				else			
					if(i-1 >= 0 && (vet[i].top()[0] == vet[i-1].top()[0] || vet[i].top()[1] == vet[i-1].top()[1]) )
					{
						vet[i-1].push(vet[i].top());
						vet[i].pop();
						if(vet[i].empty())
							vet.erase(vet.begin()+i);
						i = i-1;
						itr=vet.begin()+i;
					}
					else
					{
						i++;
						itr++;
					}
		}
			m = vet.size();
			i=0;
			printf("%d pile%s remaining:",m,(m != 1) ? "s":"");
			while(i!=m)
				printf(" %d",vet[i++].size());
			printf("\n");
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in","r",stdin);
	string a;
	while(1)
	{
		getline(cin,a);
		if(a=="DONE") break;
		vector<char> vet;
		stringstream fluxo(a);
		char aux;
		while(fluxo>>aux)
		{
			if((aux>='a'&& aux<='z')) vet.push_back(aux);	
			if((aux>='A' && aux<='Z'))  vet.push_back(aux+(97-65));
		}
		int flag = 1;
		for(int i = 0 ; i<(int)vet.size();i++){
			if(vet[i] != vet[vet.size()-1-i]){
				flag = 0;
				break;
			}
		}
		if(flag) cout<<"You won't be eaten!"<<endl;
			else cout<<"Uh oh.."<<endl;
		vet.clear();
	}
}

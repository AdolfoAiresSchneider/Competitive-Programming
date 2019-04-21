#include <bits/stdc++.h>
using namespace std;

int main()
{
	//~ freopen("in","r",stdin);
	string a;
	vector<int> m;
	int resp = 0;
	while(cin>>a)
	{
		int soma = 0, i,aux , brother;
		if(a[a.size()-1] == '?') continue;
		m.clear();
		for(i = 0; a[i] != '=' ;i++){
			if(a[i] == '+'){
				m.push_back(1);
				a[i] = ' ';
			}
			if(a[i] == '-'){
				m.push_back(-1);
				a[i] = ' ';
			}
		}
		stringstream fluxo(string(a.begin(),a.begin()+i));
		stringstream b(string(a.begin()+i+1,a.end()));
		b>>brother;
		i = 0;
		fluxo>>soma;
		while(fluxo >> aux)
			soma += aux*m[i++];
		if(soma == brother) resp++;
	}
	cout<<resp<<endl;
}	

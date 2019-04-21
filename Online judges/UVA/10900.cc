#include <bits/stdc++.h>
using namespace std;
// apenas montar a expressao de acordo com as variaveis que ele dá, tipo uma arvore
map<string,string> var;
map<string,string> op; // operador + ou *

int main()
{
	int exp = 1;
	int casos,n;
	scanf("%d",&casos);
	string a,aux,b,c,d,expressao;
	while(casos--)
	{
		var.clear(); op.clear();
		scanf(" %d",&n);
		
		while(n--)
		{
			expressao.clear(); 
			
			cin>>a>>aux; // ignoro o aux
			cin.ignore();
			getline(cin,aux);
			stringstream fluxo(aux);
			fluxo>>b>>c>>d;
			
			if(isdigit(b[0]))  expressao += b;
			else
			{	if((c == "+" && op[b] == "*" )|| op[b] == c ) expressao += var[b];
				else if(c == "*" && op[b] == "+") expressao += '(' + var[b] + ')';
			}
			expressao += c;
			if(isdigit(d[0]))  expressao += d;
			else
			{ 
				if(op[d] == "*" && c == "+") expressao += var[d];
				else if((op[d] == "+" && c == "*") || op[d] == c) expressao += '(' + var[d] + ')';
			}	
			var[a] = expressao;
			op[a] = c;
		}
					
		printf("Expression #%d: ",exp++);
		cout<<var[a]<<endl;
	}
}

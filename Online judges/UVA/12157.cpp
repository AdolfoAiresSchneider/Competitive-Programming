#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a,c;
	
  cin>>n;
	int caso = 1;
  
	while(n--){
		float mile = 0, juice = 0;
		cin>>a;
		
    while(a--){
			cin>>c;
			mile += c/30+1;
			juice += c/60 + 1;  
		}
		
		mile *= 10;
		juice *= 15;
		if(mile<juice)
			cout<<"Case "<<caso++<<": Mile " <<mile<<endl;
		else if(mile>juice) cout<<"Case "<<caso++<<": Juice " <<juice<<endl;
		else
			cout<<"Case "<<caso++<<": Mile Juice " <<juice<<endl;
	}
}

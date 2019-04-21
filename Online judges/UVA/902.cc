#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> l;

int main()
{
	//~ freopen("in","r",stdin);
	int n,c;
	string a,resp;
	while(scanf("%d",&n) != EOF)
	{
		cnt.clear();
		c = 0;
		cin>>a;
		for(int i  = 0; i < (int)a.size() - (n-1); i++)
			cnt[string(a.begin()+i , a.begin() + i + n )]++;
		
		for(map<string,int>::iterator it = cnt.begin() ; cnt.end() != it; it++){
			if(it->second >= c){
				resp = it->first;
				c = it->second;
			}
		}
		cout<<resp<<endl;
	}
}

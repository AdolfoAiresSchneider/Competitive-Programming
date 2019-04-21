#include <bits/stdc++.h>
using namespace std;

int letraa[30];
int letrab[30];

int main()
{
	//~ freopen("in","r",stdin);
	string a,b;
	while(getline(cin,a) && getline(cin,b))
	{
		memset(letraa,0,sizeof (letraa));
		memset(letrab,0,sizeof (letrab));
		
		for(int i = 0; i < (int)a.size();i++) letraa[a[i] - 'a']++;
		for(int i = 0; i < (int)b.size();i++) letrab[b[i] - 'a']++;
		
		for(int i = 0 ; i < 26;i++)
		{
			for(int j = min(letraa[i],letrab[i]);j > 0;j--){
				printf("%c",i+'a');
			}
		}
		puts("");
	}
}

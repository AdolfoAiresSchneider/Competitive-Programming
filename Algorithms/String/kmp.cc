#include <bits/stdc++.h>
using namespace std;

#define maxn 100000

string T, P;
int b[maxn];

// Aplicações 
/*
 *  --> Strings root : (n%(n-b[n-1]-1) == 0 ? n/(n-b[n-1]-1) : 1)
 * 
 *  --> Convert a string to a palindrome by appending at its beginning the minimum number of letters. 
 *      - Make a string str = s + # + reverse(s) and calculate kmp of this string
 * */

void kmp(int n)
{
  b[0] = -1;
	for(int i = 1 ; i < n ; i++)
  {
    int x = b[i-1];
		while(x != -1 && P[i] != P[x+1] ) x = b[x];
    if(x == -1) b[i] = P[0] == P[i] ? 0 : -1;
    else  b[i+1] = x+1;
	}
}

void kmpsearch(int n, int m)
{
	int x = 0;
	for(int i = 0 ; i < n ; ++i)
  {
		while(x >= 0 && T[i] != P[x]) 
      x = b[x];
		x++;																		
		
    if(x == m)
    {															
			cout << " ocorrencia de P em T na posição : " 
        << i+1 - x << endl;
			x = b[x];
		}
	}
}

string from_prefix_function(int n)
{
    string str (n, '.');
    char current_symbol = 'a';
    for (int i = 0; i < n; ++i) 
    {
        if (b[i] != -1) str[i] = str[b[i]];
        else  str[i] = current_symbol++;
    }
    return str;
}


void prefix_to_z(int n) 
{
  // reconstrua a string e rode Z_funciont
 //   z_function(from_prefix_function(n));
}



int main()
{	
	cin >>P;
	kmp(P.size());
  cout<<from_prefix_function(P.size())<<endl;
}

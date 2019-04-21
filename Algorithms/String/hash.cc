#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef pair<long,long> ll;
const long long mod = 1000000007;
#define maxn 5009

// Hash --> F(R) = hash(S[0,R])=(∑ = Si∗p^i)%MOD
/*
 * - Try to use two hashs to identify a string in case of much colisions, 
 *      diferente bases or the pair (normal hash, reverse hash) is also acceptable.
 * - Usual primes for bases : 31 , 153, 163 ...
 * */ 
 
//  Largest substring that apears twice as a substring : Do binary search in the answer
/*
 * 
 * */
 
// Hash of concatenation  --> hash(S3) = hash(S1) + hash(S2) ∗ (B^n)%Mod

struct sHash
{
  int n;
  ull R[maxn], L[maxn], B[maxn];
	
	void build(string a , int base = 31)
	{
		n = a.size(); 
		
    for(int i = 0; i <= n+2;i++)
			B[i] = i == 0 ? 1 : (B[i-1] * base);
		
		for(int i = 0, c ; i < n ; i++)
		{
			c = a[i]-'a'+1;
			R[i] = i > 0 ? (R[i-1] * base + c) : c;
		}
		
		for(int i = n-1, c ; i >= 0 ; i--)
		{
			c = a[i]-'a'+1;
			L[i] = (i < n-1 ? (L[i+1] * base + c) : c);
		}
	}
  
	ull sub_hash(int i, int j)
	{
		if(i == 0) return R[j];
		return (R[j] - R[i-1] * B[j-i+1]);
	}
	
	ull r_sub_hash(int i, int j)
	{
		if(j == n - 1) return L[i];	
		return (L[i] - L[j+1] * B[j-i+1] );
	}
	
} s1, s2;

int dp[maxn][maxn];

// Number of substrings that are palindromes n^2
//   It can be done in nLogn manacher algorithm (LPS) and bit-tree or prefix sum
//     each center can make palindromes in this way --> x - 2k (where x - 2k > 0). 

int f(int i , int j)
{
	if(j < i)
		return 0;
		
	if(j == i)
		return 1;
		
	int & R = dp[i][j];
	
	if(R != -1)
		return R;
		
	ull a = s1.sub_hash(i, j), b = s1.r_sub_hash(i, j);
		
	return R = (a==b) + f(i+1, j) + f(i, j-1) - f(i+1, j-1) ;
}

string str1, str2;
// Retorna o indice do primeiro caractere diferente entre str1 e str2 em log !!
int G(int n, int m)
{
	int l = 0, r = min(n, m);
	while(l < r)
	{
		int mid = (l+r)/2;
    
    int a = s1.sub_hash(0, mid);
    int b = s2.sub_hash(0, mid);
    
		if(a == b) l = mid+1;
		else r = mid;
	}
	return str1[l] != str2[l] ? l : -1;
} // -1 as strings sao iguais !!

int main()
{
	//~ freopen("in", "R", stdin);
	
	cin.sync_with_stdio(0), cin.tie(0);
	int q; 
  string str;
	cin>>str>>q;
	
	s1.build(str);
	
	memset(dp, -1, sizeof dp);
	
	while(q--)
	{
		int L, R;
		cin>>L>>R;
		cout<<f(L-1, R-1)<<'\n';
	}
}

# include<iostream>
# include<cstdlib>
# include<cstring>
# include<cstdio>
 
 typedef long long int lli;
 
 
 using namespace std;
 
 namespace SuffixArray{
 
# define MAX_N 3001
char STR[MAX_N];
int n;
int RA[MAX_N], tRA[MAX_N];
int SA[MAX_N], tSA[MAX_N];
int LCP[MAX_N];
int c[MAX_N];
 
void countSort(int k) {
  int i, sum, maxi = max(300, n);
  memset(c, 0, sizeof c);
  for (i = 0; i < n; i++)
    c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i]; c[i] = sum; sum += t;
  }
  for (i = 0; i < n; i++)
    tSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
  for (i = 0; i < n; i++)
    SA[i] = tSA[i];
}
 
void buildSA() {
  int i, k, r;
  for (i = 0; i < n; i++) RA[i] = STR[i];
  for (i = 0; i < n; i++) SA[i] = i;
  for (k = 1; k < n; k <<= 1) {
    countSort(k);
    countSort(0);
    tRA[SA[0]] = r = 0;
    for (i = 1; i < n; i++)
      tRA[SA[i]] =
      (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
    for (i = 0; i < n; i++)
      RA[i] = tRA[i];
    if (RA[SA[n-1]] == n-1) break;
  }
}
 
 
void buildLCP(){
	//for all suffixes starting from location i onwards
	for(int i=0,k=0;i<n;++i,k?--k:0){
		if(RA[i]==n-1){k==0;continue;} //this is last suffix in SA
		int j=SA[RA[i]+1];
		while(i+k < n && j+k < n && STR[i+k] == STR[j+k])++k;
		LCP[RA[i]] = k;
	}
}
 
// namespace ends
}
 
using namespace SuffixArray;
 
 lli how_many(int n){
 
    int x = n - SA[0];
    lli ans = x ;
 
 
    for(int i = 0 ; i < n-1; ++i){
        x = n - (SA[i+1] + LCP[i]);
        ans += x;
    }
 
    return ans;
 }
 
int **allot(int n,int m){
int **st = new int*[n+1];
for(int i=0;i<=n;st[i] = new int[m+1](),++i);
return st; }
 
 int main(){
    int n,q;
    cin>>n>>q;
 
    char *str = new char[n+1]();
 
    int **mat = allot(3000,3000);
 
 
    cin>>str;
 
    int a,b;
 
    while(q--){
        cin>>a>>b;
 
        if(a == b){cout << 1 <<endl;continue;}
        if(mat[a][b]){cout<<mat[a][b]<<endl;continue;}
 
        char ch = str[b+1];
        str[b+1] = 0;
        strcpy(STR,str+a);
        str[b+1] = ch;
 
        SuffixArray :: n = b-a+1;
 
        buildSA();
        buildLCP();
 
 
        cout<<(mat[a][b] = how_many(b-a+1))<<endl;
    }
 
 
 
 return 0;
 }


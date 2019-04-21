#include <bits/stdc++.h>
using namespace std;
#define maxn 100000 + 1
 
int P[maxn * 2];
 
string convert(const string &s) 
{
    string newString = "@";
    for (size_t i = 0; i < s.size(); i++) 
        newString += "#" + s.substr(i, 1);
    newString += "#$";
    return newString;
}
 
// longest palindrome substring
int lps(const string & s)
{
    string Q = convert(s);
    int c = 0, r = 0;
 
    for (int i = 1; i < (int)Q.size() - 1; i++)
    {
        int iMirror = c - (i - c);
        if(r > i)  P[i] = min(r - i, P[iMirror]);
        
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]])
            P[i]++;
            
        if (i + P[i] > r)
            c = i, r = i + P[i];
    }
 
    // Find the longest palindrome length in p.
    int maxPalindrome = 0;
 
    for (int i = 1; i < (int)Q.size() - 1; i++)
        if (P[i] > maxPalindrome) 
            maxPalindrome = P[i];
            
    return maxPalindrome;
}
 
int main()
{
  
  //~ freopen("in", "r", stdin);
  int n;
  cin>>n;
  
  while(n--)
  {
    memset(P, 0, sizeof P);
    string s;
    cin>>s;
    int d = lps(s), ans = 0;
    for(int i = 0; i <= 2*s.size(); i++)
    {
      if(P[i] == d)
        ans++;
    }
    
    cout<<d<<' '<<ans<<endl;
  }
  
}
 

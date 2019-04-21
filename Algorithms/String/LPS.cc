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

// Longest palindrome substring.
// Number of lps(just count how many times the lps apears in P).

string lps(const string &s)
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
    int maxPalindrome = 0, centerIndex = 0;

    for (int i = 1; i < (int)Q.size() - 1; i++)
        if (P[i] > maxPalindrome) 
            maxPalindrome = P[i], centerIndex = i;

    cout << maxPalindrome << "\n";
    return s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}

int main()
{
    string s;
    cin>>s;
    cout << lps(s);
    return 0;
}

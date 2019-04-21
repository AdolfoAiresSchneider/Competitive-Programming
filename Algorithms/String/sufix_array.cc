#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define maxn 100009

/* Longest common subsequence of N of strings
 * 
 *  1 - Make the suffix array of all strings concatenates (s1@s2$s3).
 *  2 - Do a sliding window, we need to have at least one suffix of each string in the window.
 *  3 - The answer is the lcp of de first-last in the window.
 * 
 * */

/* Minimum lexicographic rotation
 * 
 *  1 - Build the suffix array.
 *  2 - Take the first suffix with lenth >= N.
 * 
 * */ 
 
/* Given an integer K, find the length of the longest substring that appears in the text at least K times 
 * 
 *  1 - Build the suffix array.
 *  2 - Sliding window of lenth k, take the lcp of the window (i , i+k-1) .
 * 
 * */
 
/* Longest Repeted Substring
 *  
 *  1 - It is the largest common prefix in the lcp array. 
 * 
 * */
 
/* Compare two substrings of the same string in O(1) time complexity
 * 
 * 1 - Usa Hashhhh!!!
 * 
 * */
 



vi suffix_array(string s) // O(n) build
{
    int n = s.size(), N = n + 256;
    vi sa(n), ra(n);
    for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
    for(int k = 0; k < n; k ? k *= 2 : k++)
    {
        vi nsa(sa), nra(n), cnt(N);
        for(int i = 0; i < n; i++) nsa[i] = (nsa[i] - k + n) % n;
        for(int i = 0; i < n; i++) cnt[ra[i]]++;
        for(int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];
 
        int r = 0;
        for(int i = 1; i < n; i++)
        {
            if(ra[sa[i]] != ra[sa[i - 1]]) r++;
            else if(ra[(sa[i] + k) % n] != ra[(sa[i - 1] + k) % n]) r++;
            nra[sa[i]] = r;
        }
        ra = nra;
    }
    return sa;
}

/* LCP ---------------------------------------------------------
 * 
 *  LCP[i] = longest common prefix of suffix[i] and suffix[i+1].
 * 
 * */
 
vi kasai(string s, vi sa) // O(n) build
{
    int n = s.size(), k = 0;
    vi ra(n), lcp(n);
    for(int i = 0; i < n; i++) ra[sa[i]] = i;
    for(int i = 0; i < n; i++)
    {
        if(k) k--;
        if(ra[i] == n - 1) {k = 0; continue;}
        int j = sa[ra[i] + 1];
        while(k < n && s[(i + k) % n] == s[(j + k) % n]) k++;
        lcp[ra[i]] = k;
        if(ra[(sa[ra[i]] + 1) % n] > ra[(sa[ra[j]] + 1) % n]) k = 0;
    }
    return lcp;
}


/* Number of distincs substrings(it's  also possible using trie, counting the number of nodes !!)
 * 
 *  All characters that are not part of the longest 
    common prefix contribute to a distinct substring.
    * 
    * 
 * */
 
int countDistinctSubstrings(string a)
{
  int n = a.size();
  vi sa = suffix_array(a);
  vi lcp = kasai(a, sa);

  int ans = n - sa[0];
  for(int i = 1; i < (int)lcp.size() ; i++)
    ans += (n - sa[i]) - lcp[i-1];
  return ans+1;
}


int n;
int suffix_len(int i)
{
  return n-i-1;
}

ll Sum_of_all_distincts_substrings_lenths(string str)
{
  
  int p[str.size()+10];
  n = str.size();
  for(int i = 0; i <= n+10; i++)
    p[i] = p[i-1] + i;
  
  str += '#'; // change the ordenation(become -- > a, aa, aa)
  vi SA = suffix_array(str);
  vi LCP = kasai(str, SA);
  
  ll ans = p[suffix_len(SA[0])];
  for(int i = 0; i < (int)LCP.size()-1; i++)
  {
    int s = suffix_len(SA[i+1]);
    ans += (p[s] - p[LCP[i]]);
  }
  
  return ans;
}






int main()
{
  //~ freopen("in", "r", stdin);
  
}


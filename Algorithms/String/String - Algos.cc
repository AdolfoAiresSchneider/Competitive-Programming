#include <bits/stdc++.h>
using namespace std;

#define maxn 1000010

string s, t;
int z[maxn], p[maxn];

// compute Z function of string s
void zfunction(const string& s)
{
  int n = s.size();
  int l = 0, r = 0;               // intervalo com maior r tal que S[l..r] = S[0..r-l+1]
                                  // nota: 1 <= l <= i <= r ou o estado é inválido
  z[0] = n;                                   // este número não importa =)
  for (int i = 1; i < n; ++i)
    if (i <= r && z[i - l] <= r - i)          // se é impossível formar prefixo
      z[i] = z[i - l];                        // apenas pega o z do prefixo no início
    else
    {
      l = i;                                  // reinicia o intervalo para posição atual
      if (i > r) r = i;                       // se termina atrás: chega pra frente
      while (r < n && s[r - l] == s[r]) ++r;  // procura o maior r
      z[i] = r - l;                           // achou diff.: salva tamanho
      --r;                                    // * r não é válido (caracter diff.) *
    }
}

// compute prefix function of s
void prefix(const string& s)
{
  p[0] = -1;
  int i = 0, j = -1, n = s.size();
  while (i < n)
  {
    while (j >= 0 && s[i] != s[j]) j = p[j];
    p[++i] = ++j;
  }
}

// convert z function to prefix function
void z_to_prefix(int n)
{
  memset(p, 0, sizeof p);
  for (int i = 1; i < n; ++i) p[i + z[i]] = max(p[i + z[i]], z[i]);
  for (int i = n; i > 0; --i) p[i - 1] = max(p[i] - 1, p[i - 1]);
  p[0] = -1;
}

// convert prefix function to z function
void prefix_to_z(int n)
{
  char current = 'A' - 1;
  string s(n, 0);

  for (int i = 1; i <= n; ++i)
    if (p[i])
      s[i - 1] = s[p[i] - 1];
    else
      s[i - 1] = ++current;

  zfunction(s);
}

// search in s for a pattern t using Z function
void match(const string& s, const string& t)
{
  string u = t + "$" + s;
  zfunction(u);
  for (int i = u.size() - 1, n = t.size(); i > n; --i)
    if (z[i] == n)
      cout << "I found \"" << t << "\" at " << i - n - 1 << " with Z function!\n";
}

// search in s for a pattern t using prefix function
void kmp(const string& s, const string& t)
{
  prefix(t);

  int i = 0, j = 0, n = s.size(), m = t.size();
  while (i < n)
  {
    while (j >= 0 && s[i] != t[j]) j = p[j];
    ++i;
    ++j;
    if (j == m)
    {
      cout << "I found \"" << t << "\" at " << i - j << " with prefix function!\n";
      j = p[j];
    }
  }
}

// Number Of Distinct Substrings with Z function O(n²)
int nods_z(const string& s)
{
  int k = 0, n = s.size();
  for (int sub = 1; sub <= n; ++sub)
  {
    string t = s.substr(0, sub);
    reverse(t.begin(), t.end());
    zfunction(t);
    int zmax = 0;
    for (int i = 1; i < sub; ++i) zmax = max(zmax, z[i]);
    k += sub - zmax;
  }

  return k;
}

// return a substring t such that s = one or more copies of t using Z function
string compress_z(const string& s)
{
  zfunction(s);

  int n = s.size(), i;
  for (i = 1; i < n && i + z[i] != n; ++i);
  return s.substr(0, i);
}

// return a substring t such that s = one or more copies of t using prefix function
string compress_prefix(const string& s)
{
  prefix(s);
  return s.substr(0, s.size() - p[s.size()]);
}

int main()
{
  return 0;
}

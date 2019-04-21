#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;


char table[5][5];
ii pos[26];

void create_table(string s) 
{
  bitset<26> used; 
  used.reset();
  used['q' - 'a'] = true;
  int p = 0;
  s += "abcdefghijklmnopqrstuvwxyz";

  for (char c : s) 
  {
    if (c >= 'a' && c <= 'z') 
    {
      if (used[c - 'a']) continue;
      used[c - 'a'] = true;
      pos[c - 'a'] = ii(p / 5, p % 5);
      table[p / 5][p % 5] = toupper(c);
      p++;
    }
  }
}

string encrypt_pair(char a , char b) 
{
  auto pa = pos[a - 'a'];
  auto pb = pos[b - 'a'];
  if (pa.first == pb.first)  // linhas iguais
  {
	pa.second++;
	pb.second++;
  } 
  else if (pa.second == pb.second) // colunas iguais
  {
    pa.first++;
    pb.first++;
  } 
  else  swap(pa.second, pb.second);
  
  string e = "  ";
  e[0] = table[pa.first % 5][pa.second % 5];
  e[1] = table[pb.first % 5][pb.second % 5];
  return e;
}

string encrypt(string s) 
{
  string resp;
  for (int i = 0; i < (int)s.size(); i++) 
  {
    if (i + 1 == (int)s.size() || s[i] == s[i + 1])  resp += encrypt_pair(s[i], 'x');
    else {
      resp += encrypt_pair(s[i], s[i + 1]);
      i++;
    }
  }
  return resp;
}


string normalize(string s) 
{
  string r = "";
  for (char c : s)  if (c >= 'a' && c <= 'z') r += c;
  return r;
}

int main() 
{
  //~ freopen("in","r",stdin);
  int tcc;
  string s;
  cin >> tcc;
  getline(cin, s);
  while (tcc--) 
  {
    getline(cin, s);
    create_table(normalize(s));
    getline(cin, s);
    cout << encrypt(normalize(s)) << endl;
  }
}

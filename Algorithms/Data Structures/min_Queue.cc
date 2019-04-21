#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

#define st first
#define nd second

struct min_queue
{
  int qtd;
  stack<ii> s1, s2;
  
  min_queue(){
    qtd = 0;
  }
  
  int Min(){
    if(s1.empty() || s2.empty())
      return s1.empty() ? s2.top().nd : s1.top().nd;
    return min(s1.top().nd, s2.top().nd);
  }
  
  void Push(int x)
  {
    s1.push(ii(x, s1.empty() ? x : min(x, s1.top().nd))), qtd++;
  }
  
  void Pop()
  {
    if(s2.empty()){
      while(s1.size()){
        int x = s1.top().st; s1.pop();
        s2.push(ii(x, s2.empty() ? x : min(x, s2.top().nd)));
      }
    }
    s2.pop(), qtd--;
  }
};

int main()
{
  min_queue Q;
}

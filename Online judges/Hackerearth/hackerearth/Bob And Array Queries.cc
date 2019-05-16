#include <bits/stdc++.h>
using namespace std;

#define maxn 500009

int BIT[maxn], n, q;
void upd(int x, int val){
  for(; x <= n; x += x&-x)
    BIT[x] += val;
}

int query(int x){
   int sum = 0;
   for(; x > 0; x -= x&-x){
      sum += BIT[x];
    }
  return sum;
}

int main()
{
  cin.sync_with_stdio(0), cin.tie(0);
	//~ freopen("in", "r", stdin);
  
  cin>>n>>q;
	while(q--){
    int x, y, op;
    cin>>op>>x;
		if(op == 1) upd(x, 1);
		else if(op==2){
			y = query(x);
			if(x > 1) y -= query(x-1);
			if(y >= 1) upd(x,-1);
		}
		else{
      cin>>y;
      cout<<query(y)-query(x-1)<<endl;
		}
	}
}

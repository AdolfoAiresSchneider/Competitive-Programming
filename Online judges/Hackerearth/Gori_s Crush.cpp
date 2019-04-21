#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define maxn 100009
#define all(a) a.begin(), a.end()
#define pb push_back
#define sz(a) (int)a.size()
#define nd second
#define st first
#define endl '\n'

int n, q, k, bit[maxn*6],a ,b ,c ,d, p[maxn];
map<int,int> id;
vector<ii> arr;


struct node{
  int op, x, y, z;
  node(int op, int x, int y, int z) : op(op), x(x), y(y), z(z){}
};

vector<node> upd;

void reMap(){
  sort(all(arr));
  for(int i = 1; i <= sz(arr); i++)
    if(id[arr[i-1].st] == 0) id[arr[i-1].st] = i;
}

void update(int idx, int x){
  for(; idx <= sz(arr); idx += (idx&-idx)){
    bit[idx] += x;
  }
}

ll query(int idx){
  ll sum = 0;
  for(; idx > 0 ; idx -= (idx & -idx)){ 
    sum += bit[idx];
  }
  return sum;
}

int range(int i, int j){
  return query(j) - query(i-1);
}

string f(int l, int r){
  int i = id[l], j = id[r];
  int m = range(i, j);
  if(m >= k) return "Propose";
  else return "Do not propose";
}

int main(){
  
  cin.sync_with_stdio(0), cin.tie(0);
  //~ freopen("in", "r", stdin);
  cin>>n>>q>>k;
  for(int i = 0; i < n; i++){
    int x;
    cin>>x;
    p[i+1] = x;
    arr.pb({x,1});
  }
  
  while(q--){
    int op;
    cin>>op;
    if(op == 0){
      int x,y;
      cin>>x>>y;
      arr.pb({y, 0}), upd.pb(node(0,x,y,-1));
    }else{ 
      cin>>a>>b>>c>>d;  
      upd.pb(node(a,b,c,d));
      arr.pb({a,0}), arr.pb({b,0}), arr.pb({c,0}), arr.pb({d,0});
    }
  }
  reMap();
  for(ii x : arr){
    if(x.nd) update(id[x.st], 1);
  }
  
  for(node t : upd){
    a = t.op, b = t.x, c = t.y, d = t.z;
    if(t.op == 0){
      update(id[p[t.x]], -1);
      p[t.x] = t.y;
      update(id[p[t.x]], 1);
    }else{
      a = t.op, b = t.x, c = t.y, d = t.z;
      if(c < a) swap(a,c), swap(b,d);
      if(b < c)  cout<<"Do not propose"<<endl;
      else cout<<f(max(a,c), min(b,d))<<endl;
    }
  }
}


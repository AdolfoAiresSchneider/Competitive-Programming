
#include <bits/stdc++.h>
using namespace std;


set<int> st;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
    while(n--){
      int u, v;
      cin>>u>>v;
      st.insert(u);
      st.insert(v);
    }
    cout<<st.size()<<endl;
    st.clear();
	}
	
}

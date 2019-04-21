#include <bits/stdc++.h>
using namespace std;

bool isTree(int n, int sumDeg){
	return 2*(n-1) == sumDeg;
}

int main(){
	int n, sum = 0;
	cin>>n;
	for(int i = 0; i < n; i++){
		int x;
		cin>>x;
		sum += x;
	}
	if(isTree(n, sum)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

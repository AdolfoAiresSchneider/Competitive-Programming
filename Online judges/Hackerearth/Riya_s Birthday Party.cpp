#include <map>
#include <iostream>
using namespace std;

#define mod 1000000007

long long f(long long n) {
  return (n%mod*(n%mod+1ll))/2ll%mod;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    long long x;
    cin>>x;
    cout<<f(2*x-1)<<endl;
  }
}


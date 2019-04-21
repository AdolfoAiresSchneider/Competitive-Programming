#include<bits/stdc++.h>
using namespace std;

int read_int () {
	bool minus = 0,  result = 0;
	char c;
	c = getchar();
	while (1) {
		if (c == '-') break;
		if (c >= '0' && c <= '9') break;
		c = getchar();
	}
  
	if (c == '-') minus = 1;
  else result = c-'0';
  
	while (1) {
		c = getchar();
		if (c < '0' || c > '9') break;
		result = result*10 + (c - '0');
	}
  
  return minus ? -result : result;
}


int main(){
}

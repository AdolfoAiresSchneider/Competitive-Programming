#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    ll sz = s.size(), cnt = 0;
    ll x = n/sz;
    for(char c : s){
        if(c == 'a') cnt++;
    }
    ll ans = n/sz*cnt;
    for(int i = 0; i < n%sz; i++)
        if(s[i] == 'a') ans++;
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}


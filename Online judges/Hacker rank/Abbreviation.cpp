#include <bits/stdc++.h>
using namespace std;

#define maxn 1004
int dP[maxn][maxn], n, m, p[maxn];

int f(string & a, string & b)
{
        memset(dP, 0, sizeof dP), memset(p, 0, sizeof p);
    
    int j = 0;
    while(islower(a[j])) { p[j] = 1; j++;}
    
    for(int i = 1; i <= n; i++)
            dP[i][0] = p[i-1];
    
    dP[0][0] = 1;
    for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(toupper(a[i-1]) == b[j-1]) dP[i][j] |= dP[i-1][j-1];
                if(islower(a[i-1])) dP[i][j] |=  dP[i-1][j];
            }
        }
        return dP[n][m];
}


string f1(string & a, string & b) {

    n = a.size(),m = b.size();
    if(f(a,b)) return "YES";
    return "NO";

}

int main()
{
    cin.sync_with_stdio(0), cin.tie(0);
    ofstream fout(getenv("OUTPUT_PATH"));
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    

    int q;
    cin >> q;
        cin.ignore();
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = f1(a, b);

        fout << result << "\n";
    }

    return 0;
}


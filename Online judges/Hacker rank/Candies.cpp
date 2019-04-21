#include <bits/stdc++.h>

using namespace std;
#define maxn 100009
#define pb push_back
vector<int> g[maxn];
int d[maxn], ans[maxn], vis[maxn];

int f(int u)
{
    if(vis[u]){
        return ans[u]+1;
    }
    vis[u] = 1;
    for(auto v : g[u]){
        ans[u] = max(ans[u], f(v));
    }
    return ans[u]+1;
}

long candies(int n, vector<int> arr) {
    for(int i = 0; i < (int)arr.size(); i++){
            if(i && arr[i-1] < arr[i]) {
                g[i].pb(i-1);
                d[i-1]++;
            }
            if(i < n-1 && arr[i+1] < arr[i]) {
                g[i].pb(i+1);
                d[i+1]++;
            }
    }
        for(int i = 0; i < (int)arr.size(); i++){
              ans[i] = 1;
                if(d[i] == 0) g[arr.size()].pb(i);
            }
            
            f(arr.size());
            long s = 0;
            for(int i = 0; i < (int)arr.size(); i++)
                s += ans[i]; 
            return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}


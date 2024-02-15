#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;
long long t, n, lohi[maxn][2], ans[maxn][2], u, v;
vector<long long> al[maxn];

void dfs(int node, int par){
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        if(to != par){
            dfs(to, node);
            for(int j=0; j<2; j++){
                ans[node][j] += max(abs(lohi[node][j] - lohi[to][0]) + ans[to][0], abs(lohi[node][j] - lohi[to][1]) + ans[to][1]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> lohi[i][0] >> lohi[i][1];
            ans[i][0] = 0; ans[i][1] = 0;
            al[i].clear();
        }
        for(int i=1; i<n; i++){
            cin >> u >> v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        dfs(1, 0);
        cout << max(ans[1][0], ans[1][1]) << endl;
    }
}

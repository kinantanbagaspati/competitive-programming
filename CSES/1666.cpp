#include <bits/stdc++.h>
using namespace std;

vector<long long> al[100069];
vector<pair<long long, long long> >ans;
bool vis[100069];

void init(long long n, long long m){
    for(int i=1; i<=n; i++){
        vis[i] = false;
    }
    long long u, v;
    while(m--){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
}

void dfs(long long node){
    vis[node] = true;
    for(int i=0; i<al[node].size(); i++){
        if(!vis[al[node][i]]){
            dfs(al[node][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m;
    cin >> n >> m;
    init(n,m);
    dfs(1);
    long long prev = 1;
    for(int i=2; i<=n; i++){
        if(!vis[i]){
            dfs(i);
            ans.push_back({prev,i});
            prev = i;
        }
    }
    cout << ans.size() << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

vector<long long> al[100069], ans;
long long par[100069];

void init(long long n, long long m){
    long long u, v;
    while(m--){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        par[i] = -1;
    }
}

bool dfs(long long node){
    bool found = false;
    for(int i=0; i<al[node].size() && !found; i++){
        if(par[al[node][i]]<0){
            par[al[node][i]] = node;
            found = dfs(al[node][i]);
        }else if(par[node] != al[node][i]){
            found = true;
            long long cur = al[node][i];
            ans.push_back(cur);
            cur = node;
            while(cur != ans[0]){
                ans.push_back(cur);
                cur = par[cur];
            }
            ans.push_back(cur);
        }
    }
    return found;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m;
    cin >> n >> m;
    init(n, m);
    bool found = false;
    for(int i=1; i<=n && !found; i++){
        if(par[i]<0){
            par[i] = 0;
            found = dfs(i);
        }
    }
    if(found){
        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}

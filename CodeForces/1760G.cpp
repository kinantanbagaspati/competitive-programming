#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 131072;
int t, n, a, b, u, v, w;
vector<int> al[maxn], weight[maxn];
bool vis[maxn];
set<int> s;

void dfs1(int node, int val){
    vis[node] = true;
    s.insert(val);
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        int curw = weight[node][i];
        if(!vis[to]){
            dfs1(to, val^curw);
        }
    }
}

bool dfs2(int node, int val){
    vis[node] = true;
    if(s.count(val)){
        return true;
    }

    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        int curw = weight[node][i];
        if(!vis[to]){
            if(dfs2(to, val^curw)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        for(int i=1; i<n; i++){
            cin >> u >> v >> w;
            al[u].push_back(v);
            al[v].push_back(u);
            weight[u].push_back(w);
            weight[v].push_back(w);
        }

        for(int i=1; i<=n; i++){
            vis[i] = false;
        }
        vis[b] = true;
        s.clear();
        dfs1(a, 0);

        for(int i=1; i<=n; i++){
            vis[i] = false;
        }

        vis[b] = true;
        bool nemu = false;
        for(int i=0; i<al[b].size() && !nemu; i++){
            nemu = nemu || dfs2(al[b][i], weight[b][i]);
        }
        if(nemu){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

        for(int i=1; i<=n; i++){
            al[i].clear();
            weight[i].clear();
        }
    }
}

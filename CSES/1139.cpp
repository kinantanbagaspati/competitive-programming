#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> al[200069];
set<long long> gerak;
long long color[200069], subtree[200069], parent[200069], maxchild[200069], ans[200069];
bool vis[200069];

void init(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> color[i];
        vis[i] = false;
    }
    long long u, v;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
}
void dfs1(long long node){
    vis[node] = true;
    subtree[node] = 1;
    long long curmax = 0;
    maxchild[node] = -1;
    for(int i=0; i<al[node].size(); i++){
        long long u = al[node][i];
        if(!vis[u]){
            parent[u] = node;
            dfs1(u);
            if(subtree[u] > curmax){
                maxchild[node] = u;
                curmax = subtree[u];
            }
            subtree[node] += subtree[u];
        }
    }
}

void dfs2(long long node, bool isAns){
    for(int i=0; i<al[node].size(); i++){
        long long u = al[node][i];
        if(u != parent[node] && u!= maxchild[node]){
            dfs2(u, isAns);
            if(isAns){
                gerak.clear();
            }
        }
    }
    if(maxchild[node] > 0){
        dfs2(maxchild[node], isAns);
    }
    gerak.insert(color[node]);
    if(isAns){
        for(int i=0; i<al[node].size(); i++){
            long long u = al[node][i];
            if(u != parent[node] && u!= maxchild[node]){
                dfs2(u, false);
            }
        }

        ans[node] = gerak.size();
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    parent[1] = 0;
    dfs1(1);
    dfs2(1, true);
    for(int i=1; i<=n; i++){
        cout << ans[i] << " ";
    }cout << endl;
}

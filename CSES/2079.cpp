#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069;
long long n;
vector<long long> al[maxn], decomp_tree[maxn];
long long subtree[maxn];
bool vis[maxn], decomped[maxn];

void init(){
    cin >> n;
    long long u, v;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    for(int i=1; i<=n; i++){
        decomped[i] = false;
        vis[i] = false;
    }
}
//ngitung subtree
void dfs1(long long node, bool v){
    vis[node] = !vis[node];
    subtree[node] = 1;
    for(int i=0; i<al[node].size(); i++){
        long long u = al[node][i];
        if(!decomped[u] && vis[u] == v){
            dfs1(u, v);
            subtree[node] += subtree[u];
        }
    }
}
//ngitung minimum maxsubtree
pair<long long, long long> dfs2(long long node, bool v, long long nodes){
    vis[node] = !vis[node];
    pair<long long, long long> res;
    res = {nodes-subtree[node], node};
    for(int i=0; i<al[node].size(); i++){
        long long u = al[node][i];
        if(!decomped[u]){
            if(subtree[u]<subtree[node]){
                res.first = max(subtree[u], res.first);
            }
        }
    }
    for(int i=0; i<al[node].size(); i++){
        long long u = al[node][i];
        if(!decomped[u] && vis[u] == v){
            res = min(dfs2(u, v, nodes), res);
        }
    }
    return res;
}
long long centroid_decomp(long long par, long long root){
    dfs1(root, vis[root]);
    pair<long long, long long> p;
    p = dfs2(root, vis[root], subtree[root]);
    long long chosen = p.second;
    //cout << par << " " << chosen << endl;
    decomp_tree[par].push_back(chosen);
    decomped[chosen] = true;
    for(int i=0; i<al[chosen].size(); i++){
        long long u = al[chosen][i];
        if(!decomped[u]){
            centroid_decomp(chosen, u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    centroid_decomp(0, 1);
    cout << decomp_tree[0][0] << endl;
}

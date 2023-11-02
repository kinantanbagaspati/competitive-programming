#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;
long long n, m, u, v, w, d;
long long depth[maxn], lca[maxn][20], subtree[maxn];
vector<long long> al[maxn], children[maxn];

void dfsTree(long long node, long long par){
    lca[node][0] = par;
    depth[node] = depth[par] + 1;
    subtree[node] = 1;
    for(int i=0; i<al[node].size(); i++){
        long long to = al[node][i];
        if(to != par){
            dfsTree(to, node);
            children[node].push_back(to);
            subtree[node] += subtree[to];
        }
    }
}
void initLCA(){
    for(int i=1; i<20; i++){
        for(int j=1; j<=n; j++){
            lca[j][i] = lca[lca[j][i-1]][i-1];
        }
    }
}
long long getPar(long long node, long long gen){
    for(int i=0; i<20; i++){
        if(gen % 2){
            node = lca[node][i];
        }
        gen /= 2;
    }
    return node;
}

long long getLCA(long long a, long long b){
    if(depth[a] > depth[b]){
        a = getPar(a, depth[a] - depth[b]);
    }
    if(depth[a] < depth[b]){
        b = getPar(b, depth[b] - depth[a]);
    }
    if(a == b){
        return a;
    }
    for(int i=19; i>=0; i--){
        if(lca[a][i] != lca[b][i]){
            a = lca[a][i]; b = lca[b][i];
        }
    }
    return lca[a][0];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    depth[0] = 0;
    dfsTree(1, 0);
    initLCA();

    cin >> m;
    while(m--){
        cin >> u >> v;
        if((depth[u] - depth[v]) % 2 != 0){
            cout << 0 << endl;
        }else if(u == v){
            cout << n << endl;
        }else{
            if(depth[u] < depth[v]){
                w = u; u = v; v = w;
            } // depth[u] >= depth[v]
            w = getLCA(u, v);
            if(depth[u] == depth[v]){
                d = depth[u] - depth[w] - 1;
                cout << n - subtree[getPar(u, d)] - subtree[getPar(v, d)] << endl;
            }else{
                d = depth[w] + (depth[u] - depth[v]) / 2;
                cout << subtree[getPar(u, depth[u]-d)] - subtree[getPar(u, depth[u]-d-1)] << endl;
            }
        }
    }
}

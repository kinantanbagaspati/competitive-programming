#include <bits/stdc++.h>
using namespace std;

vector<long long> al[200069];
long long p[200069][20], depth[200069];

void init(long long n){
    long long u, v;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
}
long long dfs(long long node){
    long long c;
    for(int i=0; i<al[node].size(); i++){
        c = al[node][i];
        if(c!=p[node][0]){
            p[c][0] = node;
            depth[c] = depth[node]+1;
            dfs(c);
        }
    }
}
void lca(long long n){
    for(int j=1; j<20; j++){
        for(int i=0; i<=n; i++){
            p[i][j] = p[p[i][j-1]][j-1];
        }
    }
}

long long dis(long long a, long long b){
    long long c, idx;
    long long x, y;
    x = depth[a]; y = depth[b];
    c = depth[a]-depth[b]; idx = 0;
    while(c>0){
        if(c%2){a = p[a][idx];}
        c/=2; idx++;
    }
    c = depth[b]-depth[a]; idx=0;
    while(c>0){
        if(c%2){b = p[b][idx];}
        c/=2; idx++;
    }
    while(a!=b){
        idx=1;
        while(p[a][idx] != p[b][idx]){idx++;}
        a = p[a][idx-1]; b = p[b][idx-1];
    }
    return x - depth[a] + y - depth[b];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, q;
    cin >> n >> q;
    init(n);
    p[0][0] = 0;
    p[1][0] = 0;
    depth[0] = 0;
    dfs(1);
    lca(n);
    long long a, b;
    while(q--){
        cin >> a >> b;
        cout << dis(a, b) << endl;
    }
}

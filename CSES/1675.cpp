#include <bits/stdc++.h>
using namespace std;

const long long maxn = 100069;
long long n, m;
long long par[maxn], nbnodes[maxn];
pair<long long, pair<long long, long long> > edges[2*maxn];

void init(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        par[i] = i;
        nbnodes[i] = 1;
    }
    long long u, v, w;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        edges[i] = {w, {u, v}};
    }
}

long long getset(long long node){
    long long next;
    while(par[node] != node){
        next = par[node];
        par[node] = par[next];
        node = next;
    }
    return node;
}

long long join(long long u, long long v){
    u = getset(u); v = getset(v);
    if(nbnodes[u] < nbnodes[v]){
        par[u] = v;
        nbnodes[v] += nbnodes[u];
    }else{
        par[v] = u;
        nbnodes[u] += nbnodes[v];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    sort(edges, edges+m);
    long long nbedge = 0, ans = 0;
    for(int i=0; i<m && nbedge < n-1; i++){
        long long u = edges[i].second.first;
        long long v = edges[i].second.second;
        if(getset(u) != getset(v)){
            ans += edges[i].first;
            nbedge++;
            join(u, v);
        }
    }
    if(nbedge == n-1){
        cout << ans << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}

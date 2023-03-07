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
        return nbnodes[v];
    }else{
        par[v] = u;
        nbnodes[u] += nbnodes[v];
        return nbnodes[u];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    long long u, v, nbcom = n, maxcom = 1;
    while(m--){
        cin >> u >> v;
        if(getset(u) != getset(v)){
            nbcom--;
            maxcom = max(join(u, v), maxcom);
        }
        cout << nbcom << " " << maxcom << endl;
    }
}

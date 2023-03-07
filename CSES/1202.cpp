#include <bits/stdc++.h>
using namespace std;

const long long maxn = 100069, mod = 1e9+7;
long long n, m;
long long dis[maxn], minlen[maxn], maxlen[maxn], nb[maxn];
vector<long long> al[maxn], weight[maxn];
multiset<pair<long long, long long> > ms;

void init(){
    cin >> n >> m;
    dis[1] = 0;
    minlen[1] = 0;
    maxlen[1] = 0;
    nb[1] = 1;
    for(int i=2; i<=n; i++){
        dis[i] = 1e18;
    }
    long long u, v, w;
    while(m--){
        cin >> u >> v >> w;
        al[u].push_back(v);
        weight[u].push_back(w);
    }
}

void djikstra(){
    ms.insert({0, 1});
    while(!(ms.empty())){
        long long a = ms.begin()->first;
        long long b = ms.begin()->second;
        ms.erase({a,b});
        for(int i=0; i<al[b].size(); i++){
            long long x = al[b][i];
            long long w = weight[b][i];
            if(a + w < dis[x]){
                ms.erase({dis[x], x});
                dis[x] = a + w;
                ms.insert({dis[x], x});
                nb[x] = nb[b];
                minlen[x] = minlen[b] + 1;
                maxlen[x] = maxlen[b] + 1;
            }else if(a + w == dis[x]){
                nb[x] = (nb[x] + nb[b])%mod;
                minlen[x] = min(minlen[x], minlen[b] + 1);
                maxlen[x] = max(maxlen[x], maxlen[b] + 1);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    djikstra();
    cout << dis[n] << " " << nb[n] << " " << minlen[n] << " " << maxlen[n] << endl;
}

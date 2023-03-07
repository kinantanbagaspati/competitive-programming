#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> al[100069], weight[100069], la[100069], thgiew[100069];
long long dis[2][100069];
multiset<pair<long long, long long> > ms;

void init(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        dis[0][i] = 1e18;
        dis[1][i] = 1e18;
    }
    long long u, v, w;
    while(m--){
        cin >> u >> v >> w;
        al[u].push_back(v);
        la[v].push_back(u);
        weight[u].push_back(w);
        thgiew[v].push_back(w);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    dis[0][1] = 0;
    ms.insert({0,1});
    while(!ms.empty()){
        long long a = ms.begin()->first;
        long long b = ms.begin()->second;
        ms.erase({a,b});
        for(int i=0; i<al[b].size(); i++){
            if(dis[0][al[b][i]] > a + weight[b][i]){
                ms.erase({dis[0][al[b][i]], al[b][i]});
                dis[0][al[b][i]] = a + weight[b][i];
                ms.insert({dis[0][al[b][i]], al[b][i]});
            }
        }
    }
    dis[1][n] = 0;
    ms.insert({0, n});
    while(!ms.empty()){
        long long a = ms.begin()->first;
        long long b = ms.begin()->second;
        ms.erase({a,b});
        for(int i=0; i<la[b].size(); i++){
            if(dis[1][la[b][i]] > a + thgiew[b][i]){
                ms.erase({dis[1][la[b][i]], la[b][i]});
                dis[1][la[b][i]] = a + thgiew[b][i];
                ms.insert({dis[1][la[b][i]], la[b][i]});
            }
        }
    }
    long long mindis = 1e18;
    for(int i=1; i<=n; i++){
        for(int j=0; j<al[i].size(); j++){
            mindis = min(dis[0][i] + weight[i][j]/2 + dis[1][al[i][j]], mindis);
        }
    }
    cout << mindis << endl;
}

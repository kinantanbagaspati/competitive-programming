#include <bits/stdc++.h>
using namespace std;

long long n, m, q, dis[600][600];


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                dis[i][j] = 0;
            }else{
                dis[i][j] = 1e18;
            }
        }
    }
    long long u, v, w;
    while(m--){
        cin >> u >> v >> w;
        dis[u][v] = w;
        dis[v][u] = w;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                dis[j][k] = min(dis[j][i] + dis[i][k], dis[j][k]);
            }
        }
    }
    while(q--){
        cin >> u >> v;
        if(dis[u][v] == 1e18){
            cout << -1 << endl;
        }else{
            cout << dis[u][v] << endl;
        }
    }
}

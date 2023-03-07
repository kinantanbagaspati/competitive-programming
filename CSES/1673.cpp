#include <bits/stdc++.h>
using namespace std;

long long n, m, dis[3000];
bool change[3000], reach[3000][2];
vector<long long> al[3000], weight[3000];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        dis[i] = -1e18;
        change[i] = false;
        reach[i][0] = false;
        reach[i][1] = false;
    }
    dis[1] = 0;
    reach[1][0] = true;
    reach[n][1] = true;
    long long u, v, w;
    for(int i=0; i<m; i++){
        cin >> u >> v >> w;
        al[u].push_back(v);
        weight[u].push_back(w);
    }
    for(int i=0; i<n; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<al[j].size(); k++){
                if(dis[al[j][k]] < dis[j] + weight[j][k]){
                    dis[al[j][k]] = dis[j] + weight[j][k];
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=1; j<=n; j++){
            for(int k=0; k<al[j].size(); k++){
                reach[j][1] = reach[j][1] || reach[al[j][k]][1];
                reach[al[j][k]][0] = reach[j][0] || reach[al[j][k]][0];
                if(dis[al[j][k]] < dis[j] + weight[j][k]){
                    change[al[j][k]] = true;
                    dis[al[j][k]] = dis[j] + weight[j][k];
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(change[i] && reach[i][0] && reach[i][1]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << dis[n] << endl;
}

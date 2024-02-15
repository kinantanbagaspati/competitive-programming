#include<bits/stdc++.h>
using namespace std;

const int maxn = 131072;
int n, m, r;
int dis[maxn];
vector<int> al[maxn], w[maxn];
set<pair<int, int>> dijk, jalan;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> r >> r;
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        al[a].push_back(b); w[a].push_back(c);
        al[b].push_back(a); w[b].push_back(c);
    }
    for(int i=0; i<n; i++){
        dis[i] = (1<<30);
    }
    dis[0] = 0;
    dijk.insert({0, 0});
    while(dijk.size() > 0){
        int head = dijk.begin()->second;
        dijk.erase(dijk.begin());
        for(int i=0; i<al[head].size(); i++){
            int to = al[head][i];
            //cout << head << "->" << to << endl;
            if(dis[head] + w[head][i] < dis[to]){
                dijk.erase({dis[to], to});
                dis[to] = dis[head] + w[head][i];
                dijk.insert({dis[to], to});
            }
        }
    }

    for(int i=0; i<n; i++){
        //cout << "dis " << i << ": " << dis[i] << endl;
        if(dis[i]*2 < r){
            for(int j=0; j<al[i].size(); j++){
                int k = al[i][j];
                jalan.insert({min(i, k), max(i, k)});
            }
        }
    }
    cout << jalan.size() << endl;
}
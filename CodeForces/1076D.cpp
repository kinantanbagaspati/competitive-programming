#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 300069;
long long n, m, k, edgeInfo[maxn][3];
bool spec[maxn];
// buat dijstra
vector<long long> al[maxn];
long long dis[maxn], back[maxn];
set<pll> pq;

void dfs(int par, int node){
    for(auto edge : al[node]){
        int to = edgeInfo[edge][0];
        if(to == node){
            to = edgeInfo[edge][1];
        }
        if(to != par && spec[edge]){
            //cout << "HOI " << edge+1 << endl;
            if(k>0){
                cout << edge+1 << " "; k--;
            }
            dfs(node, to);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<m; i++){
        cin >> edgeInfo[i][0] >> edgeInfo[i][1] >> edgeInfo[i][2];
        al[edgeInfo[i][0]].push_back(i);
        al[edgeInfo[i][1]].push_back(i);
    }
    for(int i=2; i<=n; i++){
        dis[i] = 1e18;
    }
    dis[1] = 0;
    pq.insert({0, 1});
    while(!(pq.empty())){
        pll head = *(pq.begin());
        pq.erase(head);
        for(auto edge : al[head.second]){
            int to = edgeInfo[edge][0];
            if(to == head.second){
                to = edgeInfo[edge][1];
            }
            if(head.first + edgeInfo[edge][2] < dis[to]){
                pq.erase({dis[to], to});
                dis[to] = head.first + edgeInfo[edge][2];
                //cout << "back " << to << " = " << edge << endl;
                back[to] = edge;
                pq.insert({dis[to], to});
            }
        }
    }
    for(int i=2; i<=n; i++){
        //cout << "BACK " << i << " " << back[i] << endl;
        spec[back[i]] = true;
    }
    cout << min(n-1, k) << endl;
    dfs(0, 1);
    cout << endl;
}
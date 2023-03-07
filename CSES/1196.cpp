#include <bits/stdc++.h>
using namespace std;

long long n, m, k, vis[100069], d[100069][10];
vector<long long> al[100069], weight[100069];
priority_queue<pair <long long, long long> > pq;
pair <long long, long long> head;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    //inisialisasi
    for(int i=1; i<=n; i++){
        for(int j=0; j<10; j++){
            d[i][j] = 1e18;
        }
        vis[i] = 0;
    }
    long long u, v, w;
    while(m--){
        cin >> u >> v >> w;
        al[u].push_back(v);
        weight[u].push_back(w);
    }
    pq.push({0, 1});
    d[1][0] = 0;
    while(k>0){
        head = pq.top();
        pq.pop();
        long long node = head.second;
        long long dis = head.first;
        if(node == n){
            k--;
            cout << -dis << " ";
        }
        if(vis[node]<10){
            for(int i=0; i<al[node].size(); i++){
                long long expand = al[node][i];
                if(weight[node][i] - dis < d[expand][9]){
                    pq.push({dis - weight[node][i], expand});
                    d[expand][9] = weight[node][i] - dis;
                    int idx = 9;
                    while(idx>0 && d[expand][idx-1] > d[expand][idx]){
                        long long temp = d[expand][idx-1];
                        d[expand][idx-1] = d[expand][idx];
                        d[expand][idx] = temp;
                        idx--;
                    }
                }
            }
        }
        vis[node]++;
    }
}

#include<bits/stdc++.h>
using namespace std;

long long t, n, k, a, u, v;
long long q[262144], dis[262144], head, tail;
vector<long long> al[262144];
bool vis[262144];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1; i<=n; i++){
            al[i].clear(); vis[i] = false;
        }
        head = 0; tail = 0;
        while(k--){
            cin >> a; 
            dis[a] = 0; vis[a] = true;
            q[tail] = a; tail++;
        }
        for(int i=1; i<n; i++){
            cin >> u >> v;
            al[u].push_back(v);
            al[v].push_back(u);
        }
        while(head < tail){
            for(int i=0; i<al[q[head]].size(); i++){
                int to = al[q[head]][i];
                if(!vis[to]){
                    dis[to] = dis[q[head]]+1;
                    vis[to] = true;
                    q[tail] = to; tail++;
                }
            }
            head++;
        }
        cout << "dis";
        for(int i=1; i<=n; i++){
            cout << " " << dis[i];
        }cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> preq[100069];
long long deg[100069], dp[100069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    long long a, b;
    for(int i=1; i<=n; i++){
        dp[i] = 1;
        deg[i] = 0;
    }
    while(m--){
        cin >> b >> a;
        preq[a].push_back(b);
        deg[b]++;
    }
    queue<long long> q;
    for(int i=1; i<=n; i++){
        if(deg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        long long head = q.front();
        //cout << head << endl;
        q.pop();
        for(int i=0; i<preq[head].size(); i++){
            long long node = preq[head][i];
            dp[node] += dp[head];
            deg[node]--;
            if(deg[node] == 0){
                q.push(node);
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << dp[i] << " ";
    }cout << endl;
}

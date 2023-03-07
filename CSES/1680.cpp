#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> preq[100069], ans;
long long deg[100069], dp[100069], pre[100069];
bool legit[100069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    long long a, b;
    for(int i=1; i<=n; i++){
        dp[i] = 0;
        deg[i] = 0;
        pre[i] = 0;
        legit[i] = false;
    }
    while(m--){
        cin >> a >> b;
        preq[a].push_back(b);
        deg[b]++;
    }
    legit[1] = true;
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
            if(legit[head]){
                legit[node] = true;
                if(dp[node] < dp[head]+1){
                    dp[node] = dp[head]+1;
                    pre[node] = head;
                }
            }
            deg[node]--;
            if(deg[node] == 0){
                q.push(node);
            }
        }
    }
    if(legit[n]){
        cout << dp[n]+1 << endl;
        for(int i=n; i != 0; i = pre[i]){
            ans.push_back(i);
        }
        for(int i=ans.size()-1; i>=0; i--){
            cout << ans[i] << " ";
        }cout << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}

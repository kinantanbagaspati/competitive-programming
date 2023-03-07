#include <bits/stdc++.h>
using namespace std;

const long long maxn = 100069;
vector<long long> al[maxn], la[maxn];
bool vis[maxn];
vector<long long> q, scc;

void dfs1(long long node){
    vis[node] = true;
    for(int i=0; i<al[node].size(); i++){
        if(!vis[al[node][i]]){
            dfs1(al[node][i]);
        }
    }
    q.push_back(node);
}
void dfs2(long long node){
    vis[node] = true;
    scc.push_back(node);
    for(int i=0; i<la[node].size(); i++){
        if(!vis[la[node][i]]){
            dfs2(la[node][i]);
        }
    }
}

long long n, m;
long long id[maxn];

long long coin[maxn], coins[maxn], dp[maxn], ans = 0;
set<long long> preq[maxn], in[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> coin[i];
    }
    while(m--){
        long long u, v;
        cin >> u >> v;
        al[u].push_back(v);
        la[v].push_back(u);
    }

    for(int i=1; i<=n; i++){vis[i] = false;}

    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs1(i);
        }
    }

    /*
    for(int i=0; i<q.size(); i++){
        cout << q[i] << " ";
    }cout << endl;
    */

    for(int i=1; i<=n; i++){vis[i] = false;}
    long long curid = 1;
    for(int i=q.size()-1; i>=0; i--){
        if(!vis[q[i]]){
            dfs2(q[i]);
            for(int j=0; j<scc.size(); j++){
                id[scc[j]] = curid;
                //cout << scc[j] << " ";
            }//cout << endl;
            scc.clear();
            curid++;
        }
    }
    /*
    for(int i=1; i<=n; i++){
        cout << id[i] << endl;
    }
    */

    for(int i=1; i<curid; i++){
        dp[i] = 0;
        coins[i] = 0;
    }
    for(int i=1; i<=n; i++){
        coins[id[i]] += coin[i];
    }
    /*
    for(int i=1; i<curid; i++){
        cout << dp[i] << endl;
    }
    */

    for(int i=1; i<=n; i++){
        for(int j=0; j<al[i].size(); j++){
            long long a = id[i], b = id[al[i][j]];
            if(a != b){
                preq[a].insert(b);
                in[b].insert(a);
            }
        }
    }

    queue<long long> q;
    for(int i=1; i<curid; i++){
        if(in[i].size() == 0){q.push(i);}
    }
    while(!q.empty()){
        long long head = q.front();
        q.pop();
        dp[head] += coins[head];
        ans = max(ans, dp[head]);
        //cout << head << endl;
        for(set<long long> :: iterator itr = preq[head].begin(); itr != preq[head].end(); itr++){
            //cout << *itr << " ";
            dp[*itr] = max(dp[*itr], dp[head]);
            in[*itr].erase(head);
            if(in[*itr].size() == 0){
                q.push(*itr);
            }
        }
        //cout << endl;
    }
    cout << ans << endl;
}


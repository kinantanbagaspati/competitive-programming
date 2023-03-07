#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072, mod = 998244353;
long long t, n, ans, a[maxn], b;
vector<long long> al[maxn];
bool vis[maxn], selfLoop;
long long nodes, edges;

void dfs(long long node){
    vis[node] = true;
    nodes++; edges += al[node].size();
    //cout << "size " << node << ": " << al[node].size() << endl;
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        selfLoop = selfLoop || (node == to);
        if(!vis[to]){
            dfs(to);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            al[i].clear(); vis[i] = false;
            cin >> a[i];
        }
        for(int i=1; i<=n; i++){
            cin >> b;
            al[b].push_back(a[i]);
            al[a[i]].push_back(b);
        }
        ans = 1;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                nodes = 0; edges = 0; selfLoop = false;
                dfs(i);
                //cout << i << " " << nodes << " " << edges << endl;
                if(nodes * 2 == edges){
                    if(selfLoop){
                        ans = ans * n % mod;
                    }else{
                        ans = ans * 2 % mod;
                    }
                }else{
                    ans = 0;
                }
            }
        }
        cout << ans << endl;
    }
}

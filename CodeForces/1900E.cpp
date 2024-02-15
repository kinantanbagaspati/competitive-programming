#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
long long t, n, m, curc;
long long a[maxn], nodecid[maxn], ca[maxn], cindeg[maxn], csize[maxn];
bool vis[maxn];
vector<long long> al[maxn], la[maxn], cal[maxn];
vector<long long> q, scc;
pll cans[maxn], ans;

long long que[maxn], qhead, qtail;

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


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin >> t;
    while(t--){
        // input
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            cin >> a[i]; vis[i] = false;
            al[i].clear(); la[i].clear();
        }
        while(m--){
            long long u, v;
            cin >> u >> v;
            if(u != v){
                al[u].push_back(v);
                la[v].push_back(u);
            }
        }
        // sccing
        q.clear();
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                dfs1(i);
            }
        }
        for(int i=1; i<=n; i++){
            vis[i] = false;
        }
        reverse(q.begin(), q.end());
        scc.clear(); curc = 0;
        for(auto v : q){
            if(!vis[v]){
                dfs2(v);
                //cout << "comp " << curc << ":";
                ca[curc] = 0; cindeg[curc] = 0;
                for(int i=0; i<scc.size(); i++){
                    //cout << ' ' << scc[i];
                    nodecid[scc[i]] = curc;
                    ca[curc] += a[scc[i]];
                } //cout << endl;
                cans[curc] = {0,0};
                csize[curc] = scc.size();
                cal[curc].clear();
                curc++;
                scc.clear();
            }
        }
        // toposorting
        for(int i=1; i<=n; i++){
            for(int j=0; j<al[i].size(); j++){
                int ci = nodecid[i], cj = nodecid[al[i][j]];
                if(ci != cj){
                    cal[ci].push_back(cj); cindeg[cj]++;
                }
            }
        }
        qhead = 0, qtail = 0;
        for(int i=0; i<curc; i++){
            if(cindeg[i] == 0){
                que[qtail] = i; qtail++;
            }
        }
        ans = {0,0};
        while(qhead < qtail){
            int ex = que[qhead]; qhead++;
            cans[ex].first -= csize[ex];
            cans[ex].second += ca[ex];
            ans = min(ans, cans[ex]);
            for(int i=0; i<cal[ex].size(); i++){
                int to = cal[ex][i];
                cans[to] = min(cans[to], cans[ex]);
                cindeg[to]--;
                if(cindeg[to] == 0){
                    que[qtail] = to; qtail++;
                }
            }
        }
        cout << -ans.first << ' ' << ans.second << endl;
    } 
}
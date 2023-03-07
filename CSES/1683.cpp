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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
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

    cout << curid-1 << endl;
    for(int i=1; i<=n; i++){
        cout << id[i] << " ";
    }cout << endl;
}


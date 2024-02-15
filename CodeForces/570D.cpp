#include<bits/stdc++.h>
using namespace std;
#define pll pair<int, int>

const int maxn = 524288;
int n, m, par[maxn], depth[maxn], range[maxn][2], flat = 0;
char c[maxn];
int presum[maxn][32], v, h, lo[2], hi[2], mid;
vector<int> child[maxn], bfs[maxn];

void dfs(int node){
    int sz = bfs[depth[node]].size();
    if(sz){
        for(int i=0; i<32; i++){
            presum[node][i] = presum[bfs[depth[node]][sz-1]][i];
        }
    }
    presum[node][c[node] - 'a']++;
    bfs[depth[node]].push_back(node);


    range[node][0] = flat;
    for(int i=0; i<child[node].size(); i++){
        flat++; depth[child[node][i]] = depth[node] + 1;
        dfs(child[node][i]);
    }
    range[node][1] = flat;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    par[1] = 0;
    for(int i=2; i<=n; i++){
        cin >> par[i];
        child[par[i]].push_back(i);
    }
    for(int i=1; i<=n; i++){
        cin >> c[i];
        bfs[i].push_back(0);
    }
    range[0][0] = -1;
    depth[1] = 1;
    dfs(1);

    while(m--){
        cin >> v >> h;
        /*cout << "bfs:";
        for(int i=0; i<bfs[h].size(); i++){
            cout << ' ' << bfs[h][i];
        } cout << endl;*/
        for(int i=0; i<2; i++){
            lo[i] = 0; hi[i] = bfs[h].size();
            while(hi[i] - lo[i] > 1){
                mid = (lo[i] + hi[i]) / 2;
                if(range[bfs[h][mid]][0] < range[v][i] + i){
                    lo[i] = mid;
                }else{
                    hi[i] = mid;
                }
            }
        }
        //cout << "lo: " << lo[0] << ", " << lo[1] << endl;
        mid = 0;
        for(int i=0; i<32; i++){
            mid += (presum[bfs[h][lo[1]]][i] - presum[bfs[h][lo[0]]][i]) % 2;
        }
        //cout << mid << ' ';
        if(mid > 1){
            cout << "No\n";
        }else{
            cout << "Yes\n";
        }
    }
}

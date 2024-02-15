#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>
 
const int maxn = 131072, maxk=256, maxd=512;
long long n, m, u, v, curOrd = 0, curId = 0;
int depth[maxn], range[maxn][2], depthNums[maxn][maxd];
vector<int> al[maxn], depthNodes[maxn];
int idDepth[maxn], depthId[maxn];
long long segtree[maxn*2], depthCoins[maxn];
 
void dfs1(int node, int par){
    range[node][0] = curOrd;
    depth[node] = depth[par] + 1; 
    depthNodes[depth[node]].push_back(node);
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        if(par != to){
            curOrd++;
            dfs1(to, node);
        }
    }
    range[node][1] = curOrd;
}
void dfs2(int node, int par){
    if(depthNodes[depth[node]].size() > maxk){
        depthNums[node][depthId[depth[node]]] = 1;
    }
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        if(par != to){
            dfs2(to, node);
            for(int j=0; j<curId; j++){
                depthNums[node][j] += depthNums[to][j];
            }
        }
    }
    /*cout << node << ':';
    for(int i=0; i<curId; i++){
        cout << ' ' << depthNums[node][i];
    } cout << endl;*/
}
void update(int ord, long long val){
    ord += maxn;
    while(ord > 0){
        segtree[ord] += val; ord /= 2;
    }
}
long long query(int lo, int hi){
    lo += maxn; hi += maxn;
    long long ret = 0;
    while(lo <= hi){
        if(lo%2 == 1){
            ret += segtree[lo];
        } lo = (lo+1)/2;
        if(hi%2 == 0){
            ret += segtree[hi];
        } hi = (hi-1)/2;
    }
    return ret;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<n; i++){
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    depth[0] = -1;
    dfs1(1, 0);
    for(int i=0; i<maxn; i++){
        if(depthNodes[i].size() > maxk){
            depthId[i] = curId; idDepth[curId] = i; curId++;
        }
    }
    dfs2(1, 0);
    while(m--){
        cin >> u;
        if(u-1){
            cin >> u;
            long long ans = query(range[u][0], range[u][1]);
            for(int i=0; i<curId; i++){
                //cout << i << ' ' << idDepth[i] << ':' << depthCoins[idDepth[i]] << 'x' << depthNums[u][i] << endl;
                ans += depthCoins[idDepth[i]] * (long long)depthNums[u][i];
            }
            cout << ans << endl;
        }else{
            cin >> u >> v;
            if(depthNodes[u].size() > maxk){
                depthCoins[u] += v;
            }else{
                for(int i=0; i<depthNodes[u].size(); i++){
                    update(range[depthNodes[u][i]][0], v);
                }
            }
        }
    }
}
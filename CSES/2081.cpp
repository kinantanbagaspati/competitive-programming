#include <bits/stdc++.h>
using namespace std;

const int maxn = 262144;
int lok, hik, n, a, b;
vector<int> al[maxn];
int depth[maxn], maxdepth[maxn], subtree[maxn], maxchild[maxn];
int dp[32][maxn*2];
long long ans;

void update(int stid, int idx, int val){
    //cout << "update " << stid << ' ' << idx << ' ' << val << endl;
    idx += maxn;
    while(idx > 0){
        //cout << "idx " << idx << endl;
        dp[stid][idx] += val; idx /= 2;
    }
}
int query(int stid, int lo, int hi){
    //cout << "query " << stid << ' ' << lo << ' ' << hi << endl;
    lo = max(maxn, lo+maxn);
    hi = min(maxn*2-1, hi+maxn);
    int res = 0;
    while(lo <= hi){
        //cout << "lohi " << lo << ' ' << hi << endl;
        if(lo % 2 == 1){
            res += dp[stid][lo];
        } lo = (lo+1)/2;
        if(hi % 2 == 0){
            res += dp[stid][hi];
        } hi = (hi-1)/2;
    }
    return res;
}

void dfsTree(int node, int par){
    depth[node] = depth[par] + 1;
    maxdepth[node] = depth[node];
    subtree[node] = 1;
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        if(to != par){
            dfsTree(to, node);
            maxdepth[node] = max(maxdepth[node], maxdepth[to]);
            subtree[node] += subtree[to];
            if(subtree[to] > subtree[maxchild[node]]){
                maxchild[node] = to;
            }
        }
    }
}

void dfStL(int node, int par, int stid){
    if(maxchild[node] == 0){
        update(stid, depth[node], 1); return;
    }
    dfStL(maxchild[node], node, stid);
    update(stid, depth[node], 1);
    //cout << "nambah dari maxchildnya " << node << ": " << ans << " -> ";
    ans += (long long) query(stid, depth[node]+lok, depth[node]+hik);
    //cout << ans << endl;
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        if(to != par && to != maxchild[node]){
            dfStL(to, node, stid+1);

            //cout << "depth[" << to << "] = " << depth[to] << ", depth[" << node << "] = " << depth[node] << endl;
            for(int i=depth[to]; i<=maxdepth[to]; i++){
                //cout << "node to i: " << node << ' ' << to << ' ' << i << endl;
                //cout << "dari " << ans;
                ans += (long long) query(stid, depth[node]*2+lok-i, depth[node]*2+hik-i) * dp[stid+1][maxn+i];
                //cout << " ke " << ans << endl;
            }

            for(int i=depth[to]; i<=maxdepth[to]; i++){
                update(stid, i, dp[stid+1][maxn+i]);
                update(stid+1, i, -dp[stid+1][maxn+i]);
            }
        }
    }
    //cout << node << " ssudah: " << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> lok >> hik;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    dfsTree(1, 0);
    //cout << "kelar dfs" << endl;
    dfStL(1, 0, 0);
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 262144;
int k, n, a, b;
vector<int> al[maxn];
int depth[maxn], maxdepth[maxn], subtree[maxn], maxchild[maxn];
int dp[32][maxn*2];
long long ans;

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
    dp[stid][depth[node]]++;
    if(maxchild[node] == 0){return;}
    dfStL(maxchild[node], node, stid);
    ans += (long long) dp[stid][depth[node] + k];

    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        if(to != par && to != maxchild[node]){
            dfStL(to, node, stid+1);
            for(int i=depth[to]; i<=min(depth[node]+k, maxdepth[to]); i++){
                ans += (long long) dp[stid][depth[node]*2 + k - i] * dp[stid+1][i];
            }
            for(int i=depth[to]; i<=maxdepth[to]; i++){
                dp[stid][i] += dp[stid+1][i]; dp[stid+1][i] = 0;
            }
        }
    }
    //cout << node << ": " << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        al[a].push_back(b);
        al[b].push_back(a);
    }
    dfsTree(1, 0);
    dfStL(1, 0, 0);
    cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 262144;
bool vis[maxn*4];
int n, m, q, x, y;
vector<int> al[maxn*4];

void dfs(int node){
    vis[node] = true;
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        if(!vis[to]){
            dfs(to);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    for(int i=0; i<q; i++){
        cin >> x >> y; x--; y--;
        al[maxn+i].push_back(x); al[x].push_back(maxn+i);
        al[maxn+i].push_back(y+maxn*2); al[y+maxn*2].push_back(maxn+i);
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            dfs(i); ans++;
        }
    }
    for(int i=0; i<q; i++){
        if(!vis[maxn+i]){
            dfs(maxn+i); ans++;
        }
    }
    for(int i=0; i<m; i++){
        if(!vis[maxn*2+i]){
            dfs(maxn*2+i); ans++;
        }
    }
    cout << ans-1 << endl;
}
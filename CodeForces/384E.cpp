#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = (1<<18);
int n, m, a, b, inval[maxn], nodeRange[maxn][2], curOrd=0;
bool depth[maxn];
vector<int> al[maxn];

void dfsTree(int node, int par){
    nodeRange[node][0] = curOrd;
    for(int i=0; i<al[node].size(); i++){
        int to = al[node][i];
        if(to != par){
            depth[to] = !depth[node];
            curOrd++; dfsTree(to, node);
        }
    }
    nodeRange[node][1] = curOrd;
}

int segtree[2][maxn*2];
void update(int id, int node, int val){
    node += maxn;
    while(node > 0){
        segtree[id][node] += val; node /= 2;
    }
}
int query(int id, int lo, int hi){
    lo += maxn; hi += maxn;
    int ret = 0;
    while(lo <= hi){
        if(lo%2){
            ret += segtree[id][lo];
        } lo = (lo+1)/2;
        if(hi%2==0){
            ret += segtree[id][hi];
        } hi = (hi-1)/2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> inval[i];
    }
    for(int i=1; i<n; i++){
        cin >> a >> b;
        al[a].push_back(b); al[b].push_back(a);
    }
    dfsTree(1, 0);
    for(int i=1; i<=n; i++){
        //cout << "node " << i << ": " << depth[i] << " " << nodeRange[i][0] << " " << nodeRange[i][1] << endl;
        update(depth[i], nodeRange[i][0], inval[i]); update(depth[i], nodeRange[i][0]+1, -inval[i]);
    }
    while(m--){
        cin >> a >> b; a--;
        if(a){
            cout << query(depth[b], 0, nodeRange[b][0]) << endl;
        }else{
            cin >> a;
            update(depth[b], nodeRange[b][0], a); update(depth[b], nodeRange[b][1]+1, -a);
            update(!depth[b], nodeRange[b][0], -a); update(!depth[b], nodeRange[b][1]+1, a);
        }
    }
}
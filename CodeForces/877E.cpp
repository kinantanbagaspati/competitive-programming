#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = (1<<18);
int n, q, par[maxn], x;
vector<int> child[maxn];
int nodeRange[maxn][2], curOrd = 0;

void dfs(int node){
    nodeRange[node][0] = curOrd;
    for(int i=0; i<child[node].size(); i++){
        curOrd++;
        dfs(child[node][i]);
    }
    nodeRange[node][1] = curOrd;
}

int segtree[maxn*2][2], range[maxn*2][2];
void build(){
    for(int i=0; i<maxn; i++){
        range[maxn+i][0] = i;
        range[maxn+i][1] = i;
    }
    for(int i=maxn-1; i>0; i--){
        segtree[i][0] = segtree[i*2][0] + segtree[i*2+1][0];
        range[i][0] = range[i*2][0]; range[i][1] = range[i*2+1][1];
    }
}

void diligent(int node){
    if(!segtree[node][1]) return;
    segtree[node*2][1] ^= segtree[node][1];
    segtree[node*2+1][1] ^= segtree[node][1];
    segtree[node][0] = range[node][1]-range[node][0]+1-segtree[node][0];
    segtree[node][1] = 0;
}
int query(int node, int lo, int hi){
    if(lo <= range[node][0] && range[node][1] <= hi){
        //cout << range[node][0] << "-" << range[node][1] << " get " << segtree[node][1] << " ";
        if(segtree[node][1]){
            //cout << segtree[node][0] << " jadi " << range[node][1]-range[node][0]+1-segtree[node][0] << endl;
            return range[node][1]-range[node][0]+1-segtree[node][0];
        }else{
            //cout << segtree[node][0] << endl;
            return segtree[node][0];
        }
    }
    diligent(node);
    int mid = (range[node][0]+range[node][1])/2, ans=0;
    if(lo <= mid){
        ans += query(node*2, lo, hi);
    }
    if(mid < hi){
        ans += query(node*2+1, lo, hi);
    }
    return ans;
}
void update(int node, int lo, int hi){
    //cout << node << " " << lo << "-" << hi << endl;
    if(lo <= range[node][0] && range[node][1] <= hi){
        segtree[node][1] = !segtree[node][1];
        return;
    }
    diligent(node);
    int mid = (range[node][0]+range[node][1])/2;
    if(lo <= mid){
        update(node*2, lo, hi);
    }
    if(mid < hi){
        update(node*2+1, lo, hi);
    }
    segtree[node][0] = query(node*2, 0, maxn) + query(node*2+1, 0, maxn);
}

string type;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=2; i<=n; i++){
        cin >> par[i];
        child[par[i]].push_back(i);
    }
    dfs(1);
    for(int i=1; i<=n; i++){
        cin >> segtree[nodeRange[i][0]+maxn][0];
    }
    build();
    cin >> q;
    while(q--){
        cin >> type >> x;
        if(type[0] == 'g'){
            cout << query(1, nodeRange[x][0], nodeRange[x][1]) << endl;
        }else{
            update(1, nodeRange[x][0], nodeRange[x][1]);
        }
    }
}

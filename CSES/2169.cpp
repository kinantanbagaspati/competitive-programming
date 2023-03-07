#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069;
long long segtree[30*maxn], child[30*maxn][2], range[30*maxn][2], nbnodes;

void createnode(long long lo, long long hi){
    segtree[nbnodes] = 0;
    child[nbnodes][0] = -1;
    child[nbnodes][1] = -1;
    range[nbnodes][0] = lo;
    range[nbnodes][1] = hi;
    nbnodes++;
}
void build(){
    nbnodes = 0;
    createnode(1, 1e9);
}
void update(long long node, long long pos, long long val){
    if(range[node][0] == range[node][1]){
        segtree[node] += val; return;
    }
    long long mid = (range[node][0] + range[node][1])/2;
    if(pos <= mid){
        if(child[node][0] < 0){
            child[node][0] = nbnodes; createnode(range[node][0], mid);
        }
        update(child[node][0], pos, val);
    }else{
        if(child[node][1] < 1){
            child[node][1] = nbnodes; createnode(mid+1, range[node][1]);
        }
        update(child[node][1], pos, val);
    }
    segtree[node] = 0;
    for(int i=0; i<2; i++){
        if(child[node][i]>=0){segtree[node] += segtree[child[node][i]];}
    }
}
long long query(long long node, long long lo, long long hi){
    if(range[node][0] == lo && range[node][1] == hi){
        return segtree[node];
    }
    long long ret = 0, mid = (range[node][0] + range[node][1])/2;
    if(child[node][0] >= 0 && lo <= mid){
        ret += query(child[node][0], lo, min(mid, hi));
    }
    if(child[node][1] >= 0 && mid < hi){
        ret += query(child[node][1], max(mid+1, lo), hi);
    }
    return ret;
}

long long n, x, y, z;
pair<pair<long long, long long>, long long> p[maxn];
long long ans[2][maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        p[i] = {{x,-y},i};
    }
    sort(p, p+n);
    build();
    for(int i=0; i<n; i++){
        x = p[i].first.first;
        y = -p[i].first.second;
        z = p[i].second;
        ans[1][z] = query(0, y, 1e9);
        update(0, y, 1);
    }
    build();
    for(int i=n-1; i>=0; i--){
        x = p[i].first.first;
        y = -p[i].first.second;
        z = p[i].second;
        ans[0][z] = query(0, 1, y);
        update(0, y, 1);
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cout << ans[i][j] << " ";
        }cout << endl;
    }
}

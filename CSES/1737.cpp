#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long n, q;
long long segtree[30*maxn], child[30*maxn][2], range[30*maxn][2], nbnodes;
long long versionid[maxn], nbversion;

void build(){
    cin >> n >> q;
    nbnodes = 2*maxn;
    for(int i=0; i<maxn; i++){
        if(i<n){
            cin >> segtree[maxn + i];
        }else{
            segtree[maxn + i] = 0;
        }
        range[maxn+i][0] = i;
        range[maxn+i][1] = i;
        child[maxn+i][0] = 0;
        child[maxn+i][1] = 0;
    }
    for(int i=maxn-1; i>0; i--){
        segtree[i] = segtree[2*i] + segtree[2*i+1];
        child[i][0] = 2*i;
        child[i][1] = 2*i+1;
        range[i][0] = range[2*i][0];
        range[i][1] = range[2*i+1][1];
    }
    nbversion = 1;
    versionid[0] = 1;
}

void update(long long node, long long from, long long pos, long long val){
    child[node][0] = child[from][0];
    child[node][1] = child[from][1];
    range[node][0] = range[from][0];
    range[node][1] = range[from][1];
    if(range[node][0] == range[node][1]){
        segtree[node] = val; return;
    }
    if(pos <= (range[from][0] + range[from][1])/2){
        child[node][0] = nbnodes;
        nbnodes++;
        update(nbnodes-1, child[from][0], pos, val);
    }else{
        child[node][1] = nbnodes;
        nbnodes++;
        update(nbnodes-1, child[from][1], pos, val);
    }
    segtree[node] = segtree[child[node][0]] + segtree[child[node][1]];
}

long long query(long long node, long long lo, long long hi){
    if(lo == range[node][0] && hi == range[node][1]){
        return segtree[node];
    }
    long long ret = 0, mid = (range[node][0] + range[node][1])/2;
    if(lo <= mid){
        ret += query(child[node][0], lo, min(mid, hi));
    }
    if(hi > mid){
        ret += query(child[node][1], max(mid+1, lo), hi);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    build();
    long long t, k, a, b;
    while(q--){
        cin >> t;
        if(t==1){
            cin >> k >> a >> b;
            k--; a--;
            long long from = versionid[k];
            versionid[k] = nbnodes;
            nbnodes++;
            update(versionid[k], from, a, b);
        }else if(t==2){
            cin >> k >> a >> b;
            k--; a--; b--;
            cout << query(versionid[k], a, b) << endl;
        }else{
            cin >> k; k--;
            versionid[nbversion] = versionid[k];
            nbversion++;
        }
    }
}

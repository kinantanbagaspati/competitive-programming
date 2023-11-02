#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
long long n, q, a[maxn];
long long segtree[maxn*2][2], range[maxn*2][2], lazy[maxn*2][3];

void build(){
    for(int i=0; i<maxn; i++){
        range[maxn+i][0] = i;
        range[maxn+i][1] = i;
        lazy[maxn+i][0] = 1e18;
        lazy[maxn+i][1] = -1e18;
        lazy[i][0] = 1e18;
        lazy[i][1] = -1e18;
    }
    for(int i=0; i<n; i++){
        segtree[maxn+i][0] = a[i]; 
        segtree[maxn+i][1] = a[i];
    }
    for(int i=maxn-1; i>0; i--){
        segtree[i][0] = min(segtree[2*i][0], segtree[2*i+1][0]);
        segtree[i][1] = max(segtree[2*i][1], segtree[2*i+1][1]);
        range[i][0] = range[2*i][0];
        range[i][1] = range[2*i+1][1];
    }
}
pll query(long long node, long long lo, long long hi){
    if(range[node][0] == lo && range[node][1] == hi){
        return {
            min(max(segtree[node][0] + lazy[node][2], lazy[node][1]), lazy[node][0]),
            min(max(segtree[node][1] + lazy[node][2], lazy[node][1]), lazy[node][0])
        };
    }
    long long mid = (range[node][0] + range[node][1])/2;
    pll ret = {1e18, -1e18}, rec;
    if(lo <= mid){
        rec = query(2*node, lo, min(mid, hi));
        ret.first = min(ret.first, rec.first);
        ret.second = max(ret.second, rec.second);
    }
    if(mid < hi){
        rec = query(2*node+1, max(mid+1, lo), hi);
        ret.first = min(ret.first, rec.first);
        ret.second = max(ret.second, rec.second);
    }
    return ret;
}
void update(long long node, long long lo, long long hi, long long op, long long val){
    // cout << "update " << node << " (" << lo << "," << hi << ") (" << range[node][0] << "," << range[node][1] << ")" << endl;
    // lazy update
    if(range[node][0] == lo && range[node][1] == hi){
        if(op == 2){
            lazy[node][0] = min(lazy[node][0], val);
            lazy[node][1] = min(lazy[node][1], val);
        }else if(op == 3){
            lazy[node][0] = max(lazy[node][0], val);
            lazy[node][1] = max(lazy[node][1], val);
        }else{
            lazy[node][0] += val;
            lazy[node][1] += val;
            lazy[node][2] += val;
        }
        return;
    }
    // cout << "nurunin lazy" << endl;

    for(int i=0; i<6; i++){
        update(2*node+i/3, range[2*node+i/3][0], range[2*node+i/3][1], i%3+1, lazy[node][(i+2)%3]);
    }
    lazy[node][0] = 1e18;
    lazy[node][1] = -1e18;
    lazy[node][2] = 0;

    // diligent update
    long long mid = (range[node][0] + range[node][1])/2;
    if(lo <= mid){
        update(2*node, lo, min(mid, hi), op, val);
    }
    if(mid < hi){
        update(2*node+1, max(lo, mid+1), hi, op, val);
    }
    pll res0 = query(2*node, range[2*node][0], range[2*node][1]);
    pll res1 = query(2*node+1, range[2*node+1][0], range[2*node+1][1]);
    segtree[node][0] = min(res0.first, res1.first);
    segtree[node][1] = max(res0.second, res1.second);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    build();
    
    long long type, lo, hi, val;
    while(q--){
        cin >> type >> lo >> hi; lo--; hi--;
        if(type < 4){
            cin >> val;
            update(1, lo, hi, type, val);
        }else{
            update(1, lo, hi, 1, 0);
            pll ret = query(1, lo, hi);
            cout << ret.first << " " << ret.second << endl;
        }
    }
    return 0;
}
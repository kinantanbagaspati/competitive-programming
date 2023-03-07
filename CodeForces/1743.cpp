#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 524288, mod = 998244353;
long long segtree[2*maxn][2], lazy[2*maxn][2][2], range[2*maxn][2];
long long n, u, v, temp;

void build(){
    for(int i=0; i<maxn; i++){
        // lazy matriks identitas
        for(int j=0; j<2; j++){
            lazy[2*i+j][0][0] = 1;
            lazy[2*i+j][0][1] = 0;
            lazy[2*i+j][1][0] = 0;
            lazy[2*i+j][1][1] = 1;
        }
        segtree[maxn+i][0] = (i<u || v<i);
        segtree[maxn+i][1] = (u<=i && i<=v);
        range[maxn+i][0] = i;
        range[maxn+i][1] = i;
    }

    for(int i=maxn-1; i>0; i--){
        segtree[i][0] = (segtree[2*i][0] + segtree[2*i+1][0])%mod;
        segtree[i][1] = (segtree[2*i][1] + segtree[2*i+1][1])%mod;
        range[i][0] = range[2*i][0];
        range[i][1] = range[2*i+1][1];
    }
    // masukin matrix 0 sama 1 di 2*maxn-2 sama 2*maxn-1
    lazy[2*maxn-2][0][0] = 3;
    lazy[2*maxn-2][0][1] = 1;
    lazy[2*maxn-2][1][0] = 0;
    lazy[2*maxn-2][1][1] = 2;

    lazy[2*maxn-1][0][0] = 1;
    lazy[2*maxn-1][0][1] = 1;
    lazy[2*maxn-1][1][0] = 2;
    lazy[2*maxn-1][1][1] = 2;
}

long long res[2][2];
long long cross(int from, int to){
    // kaliin b ke a
    res[0][0] = (lazy[from][0][0]*lazy[to][0][0] + lazy[from][0][1]*lazy[to][1][0]) % mod;
    res[0][1] = (lazy[from][0][0]*lazy[to][0][1] + lazy[from][0][1]*lazy[to][1][1]) % mod;
    res[1][0] = (lazy[from][1][0]*lazy[to][0][0] + lazy[from][1][1]*lazy[to][1][0]) % mod;
    res[1][1] = (lazy[from][1][0]*lazy[to][0][1] + lazy[from][1][1]*lazy[to][1][1]) % mod;

    lazy[to][0][0] = res[0][0];
    lazy[to][0][1] = res[0][1];
    lazy[to][1][0] = res[1][0];
    lazy[to][1][1] = res[1][1];
}

pll getVal(int node){
    pll res;
    res.first = (lazy[node][0][0] * segtree[node][0] + lazy[node][0][1] * segtree[node][1]) % mod;
    res.second = (lazy[node][1][0] * segtree[node][0] + lazy[node][1][1] * segtree[node][1]) % mod;
    return res;
}

void diligent(int node){
    pll val = getVal(node);
    segtree[node][0] = val.first;
    segtree[node][1] = val.second;

    cross(node, 2*node);
    cross(node, 2*node+1);

    lazy[node][0][0] = 1;
    lazy[node][0][1] = 0;
    lazy[node][1][0] = 0;
    lazy[node][1][1] = 1;
}

void update(int node, int lo, int hi, int bitval){
    if(lo>hi){return;}
    if(lo == range[node][0] && hi == range[node][1]){
        cross(2*(maxn-1) + bitval, node);
        return;
    }
    diligent(node);
    int mid = (range[node][0] + range[node][1])/2;

    // rekursi
    if(lo <= mid){
        update(2*node, lo, min(mid, hi), bitval);
    }
    if(hi > mid){
        update(2*node+1, max(lo, mid+1), hi, bitval);
    }
    // rekalkulasi
    pll templl[2];
    templl[0] = getVal(2*node);
    templl[1] = getVal(2*node+1);
    segtree[node][0] = (templl[0].first + templl[1].first)%mod;
    segtree[node][1] = (templl[0].second + templl[1].second)%mod;
}

pll query(int node, int lo, int hi){
    if(lo == range[node][0] && hi == range[node][1]){
        return getVal(node);
    }
    pll res, rec;
    res.first = 0; res.second = 0;
    int mid = (range[node][0] + range[node][1])/2;
    if(lo <= mid){
        rec = query(2*node, lo, min(mid, hi));
        res.first = (res.first + rec.first) % mod;
        res.second = (res.second + rec.second) % mod;
    }
    if(hi > mid){
        rec = query(2*node+1, max(lo, mid+1), hi);
        res.first = (res.first + rec.first) % mod;
        res.second = (res.second + rec.second) % mod;
    }
    return res;
}

pll ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> u >> v;
    n--; u--; v--;
    build();
    while(n--){
        ans = query(1, 0, 3e5);
        //cout << "ans preupdate " << ans.first << " " << ans.second << endl;
        update(1, 0, 3e5, -1);
        ans = query(1, 0, 3e5);
        //cout << "ans " << ans.first << " " << ans.second << endl;
        cin >> u >> v; u--; v--;
        update(1, 0, u-1, 0);
        update(1, u, v, 1);
        update(1, v+1, 3e5, 0);
    }
    update(1, 0, 3e5, -1);
    pll res = query(1, 0, 3e5);
    //cout << "ans " << res.first << " " << res.second << endl;
    cout << res.second << endl;
}
/*
0: 111000111
1: 000111000
     111

0: 331111333
1: 002222000
*/

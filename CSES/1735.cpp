#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long n, q;
long long segtree[2*maxn], lazy[2*maxn][2], range[2*maxn][2];

void build(){
    for(int i=0; i<2*maxn; i++){
        segtree[i] = 0;
        lazy[i][0] = 0;
        lazy[i][1] = 0;
    }
    for(int i=0; i<maxn; i++){
        range[maxn + i][0] = i;
        range[maxn + i][1] = i;
    }
    for(int i=maxn-1; i>0; i--){
        range[i][0] = range[2*i][0];
        range[i][1] = range[2*i+1][1];
    }
}

void print(long long node){
    cout << node << " " << range[node][0] << "-" << range[node][1] << ": " << segtree[node] << " " << lazy[node][0] << " " << lazy[node][1] << endl;
    if(node < maxn){
        print(2*node); print(2*node+1);
    }
}

void update_lazy(long long type, long long node, long long val){
    if(type == 1){
        lazy[node][0] = 1;
        lazy[node][1] = val;
    }else{
        lazy[node][1] += val;
    }
}
long long unlazy(long long node){
    if(lazy[node][0] == 1){
        return (range[node][1] - range[node][0] + 1) * lazy[node][1];
    }else{
        return segtree[node] + (range[node][1] - range[node][0] + 1) * lazy[node][1];
    }
}

void update(long long type, long long node, long long lo, long long hi, long long val){
    //base case
    if(lo == range[node][0] && hi == range[node][1]){
        update_lazy(type, node, val);
        return;
    }
    //nurunin lazy
    if(node < maxn){
        update_lazy(lazy[node][0], 2*node, lazy[node][1]);
        update_lazy(lazy[node][0], 2*node+1, lazy[node][1]);
    }
    segtree[node] = unlazy(node);
    lazy[node][0] = 0;
    lazy[node][1] = 0;

    //return
    //if(lo == range[node][0] && hi == range[node][1]){return;}

    //rekursi
    long long mid = (range[node][0] + range[node][1])/2;
    if(lo <= mid){
        update(type, 2*node, lo, min(hi, mid), val);
    }
    if(hi > mid){
        update(type, 2*node+1, max(lo, mid+1), hi, val);
    }
    segtree[node] = unlazy(2*node) + unlazy(2*node+1);
}

long long query(long long node, long long lo, long long hi){
    //cout << node << ": " << lo << " " << hi << endl;
    //base case
    if(lo == range[node][0] && hi == range[node][1]){
        return unlazy(node);
    }
    long long ret = 0;
    long long mid = (range[node][0] + range[node][1])/2;
    if(lo <= mid){
        ret += query(2*node, lo, min(hi, mid));
    }
    if(hi > mid){
        ret += query(2*node+1, max(lo, mid+1), hi);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    build();
    cin >> n >> q;
    long long t, a, b, c;

    for(int i=0; i<n; i++){
        cin >> t;
        update(0,1,i,i,t);
        //print(65536);
        //cout << endl;
    }
    while(q--){
        cin >> t >> a >> b; a--; b--;
        if(t == 3){
            update(0,1,a,b,0);
            cout << query(1,a,b) << endl;
            //print(65555);
            //print(65556);
            //cout << endl;
        }else{
            cin >> c;
            update(t-1,1,a,b,c);
        }
    }
}

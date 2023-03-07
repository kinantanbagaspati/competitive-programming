#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long n, q, type, k, x;
long long segtree[2][2*maxn];

void update(long long id, long long pos, long long val){
    pos += maxn;
    segtree[id][pos] = val;
    pos /= 2;
    while(pos > 0){
        segtree[id][pos] = min(segtree[id][2*pos], segtree[id][2*pos+1]);
        pos /= 2;
    }
}
long long query(long long id, long long lo, long long hi){
    lo += maxn;
    hi += maxn;
    long long ret = 1e18;
    while(hi>=lo){
        if(lo%2){
            ret = min(segtree[id][lo], ret);
        }lo = (lo+1)/2;
        if(!(hi%2)){
            ret = min(segtree[id][hi], ret);
        }hi = (hi-1)/2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> x;
        update(0, i, x-i);
        update(1, i, x+i);
    }
    while(q--){
        cin >> type;
        if(type == 1){
            cin >> k >> x; k--;
            update(0, k, x-k);
            update(1, k, x+k);
        }else{
            cin >> k; k--;
            cout << min(query(0,0,k)+k, query(1,k,n-1)-k) << endl;
        }
    }
}

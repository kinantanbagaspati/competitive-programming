#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144, mod = 998244353, inv = 729486258;
long long n, q;
long long segtree[2][2*maxn], mul[2][maxn];

void build(){
    for(int i=0; i<2*maxn; i++){
        segtree[0][i] = 0;
        segtree[0][i] = 0;
    }
    mul[0][0] = 1;
    mul[1][0] = 1;
    for(int i=1; i<n; i++){
        mul[0][i] = mul[0][i-1] * 26 % mod;
        mul[1][i] = mul[1][i-1] * inv % mod;
    }
}

void update(long long id, long long pos, long long val){
    segtree[id][maxn + pos] = val * mul[id][pos] % mod;
    pos = (maxn + pos)/2;
    while(pos>0){
        segtree[id][pos] = (segtree[id][2*pos] + segtree[id][2*pos + 1])%mod;
        pos /= 2;
    }
}

long long query(long long id, long long lo, long long hi){
    long long ret = 0; lo += maxn; hi += maxn;
    while(lo <= hi){
        if(lo%2){
            ret = (ret + segtree[id][lo])%mod;
        }
        lo = (lo+1)/2;
        if(!(hi%2)){
            ret = (ret + segtree[id][hi])%mod;
        }
        hi = (hi-1)/2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //cout << 26*inv%mod << endl;
    cin >> n >> q;
    build();
    char c;
    for(int i=0; i<n; i++){
        cin >> c;
        update(0,i,c-'a');
        update(1,i,c-'a');
    }
    long long t, a, b;
    while(q--){
        cin >> t;
        if(t == 1){
            cin >> a >> c; a--;
            update(0,a,c-'a');
            update(1,a,c-'a');
        }else{
            cin >> a >> b; a--; b--;
            if(query(0, a, b) * mul[1][a] % mod == query(1, a, b) * mul[0][b] % mod){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}

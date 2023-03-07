#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long segtree[2*maxn];

void init(long long n){
    long long prev = 0;
    for(int i=0; i<maxn; i++){
        if(i<n){
            cin >> segtree[maxn+i];
            segtree[maxn+i] -= prev;
            prev += segtree[maxn+i];
        }else{
            segtree[maxn+i] = 0;
        }
    }
    for(int i=maxn-1; i>0; i--){
        segtree[i] = segtree[2*i] + segtree[2*i+1];
    }
}


long long update(long long node, long long val){
    node += maxn;
    segtree[node] += val;
    node/=2;
    while(node>0){
        segtree[node] = segtree[2*node] + segtree[2*node+1];
        node /= 2;
    }
}

long long query(long long l, long long r){
    l += maxn; r += maxn;
    long long ret = 0;
    while(l<r){
        if(r%2==0){
            ret += segtree[r];r--;
        }
        if(l%2){
            ret += segtree[l];l++;
        }
        l/=2; r/=2;
    }
    if(l==r){ret += segtree[l];}
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, q, type, a, b, v;
    cin >> n >> q;
    init(n);
    while(q--){
        cin >> type;
        if(type==1){
            cin >> a >> b >> v;
            update(a-1, v);
            update(b, -v);
        }else{
            cin >> v;
            cout << query(0, v-1) << endl;
        }
    }
}

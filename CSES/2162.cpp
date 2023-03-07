#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long n, segtree[2*maxn];

void init(){
    for(int i=0; i<maxn; i++){
        if(i<n){
            segtree[maxn+i] = 1;
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

long long binser(long long pp){
    int left=0, right=n, mid = (left+right)/2;
    pair<int, int> valmid, pr;
    valmid = {query(0,mid), !segtree[maxn+mid]};
    pr = {pp, 0};
    while(valmid != pr){
        if(valmid > pr){
            right = mid;
        }else{
            left = mid;
        }
        mid = (left+right)/2;
        valmid = {query(0,mid), !segtree[maxn+mid]};
    }
    return mid;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long k=1;
    cin >> n;
    init();
    //cout << "halo" << endl;
    long long idx, p = 0;
    for(int i=n; i>0; i--){
        p = (p+k)%i;
        idx = binser(p+1);
        cout << idx+1 << " ";
        update(idx, -1);

    }cout << endl;
}

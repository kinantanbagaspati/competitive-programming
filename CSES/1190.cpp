#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long n, q;
long long pre[2*maxn], suf[2*maxn], maxsum[2*maxn], sum[2*maxn];

void build(){
    for(int i=1; i<2*maxn; i++){
        pre[i] = 0;
        suf[i] = 0;
        maxsum[i] = 0;
        sum[i] = 0;
    }
}
void update(long long node, long long val){
    node += maxn;
    pre[node] = max(val, 0ll);
    suf[node] = max(val, 0ll);
    maxsum[node] = max(val, 0ll);
    sum[node] = val;
    node /= 2;
    while(node > 0){
        pre[node] = max(pre[2*node], sum[2*node] + pre[2*node+1]);
        suf[node] = max(suf[2*node+1], sum[2*node+1] + suf[2*node]);
        maxsum[node] = max(max(maxsum[2*node], maxsum[2*node+1]), suf[2*node]+pre[2*node+1]);
        sum[node] = sum[2*node] + sum[2*node+1];
        node /= 2;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    build();
    long long x, k;
    for(int i=0; i<n; i++){
        cin >> x;
        update(i, x);
    }
    while(q--){
        cin >> k >> x;
        update(k-1, x);
        cout << maxsum[1] << endl;
    }
}

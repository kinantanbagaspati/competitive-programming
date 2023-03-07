#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long n, q;
long long pre[2*maxn], sum[2*maxn];

void build(){
    for(int i=1; i<2*maxn; i++){
        pre[i] = 0;
        sum[i] = 0;
    }
}
void update(long long node, long long val){
    node += maxn;
    pre[node] = max(val, 0ll);
    sum[node] = val;
    node /= 2;
    while(node > 0){
        pre[node] = max(pre[2*node], sum[2*node] + pre[2*node+1]);
        sum[node] = sum[2*node] + sum[2*node+1];
        node /= 2;
    }
}
void query(long long a, long long b, long long *ret, long long *sums){
    if(a>b){return;}
    if(a%2){
        *ret = max(*ret, *sums + pre[a]);
        *sums += sum[a];
    }
    query((a+1)/2, (b-1)/2, ret, sums);
    if(b%2==0){
        *ret = max(*ret, *sums + pre[b]);
        *sums += sum[b];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    build();
    long long t, x, k;
    for(int i=0; i<n; i++){
        cin >> x;
        update(i, x);
    }
    long long ans, cur;
    while(q--){
        cin >> t >> k >> x;
        if(t == 1){
            update(k-1, x);
        }else{
            ans = 0;
            cur = 0;
            k += maxn-1;
            x += maxn-1;
            query(k, x, &ans, &cur);
            cout << ans << endl;
        }
    }
}

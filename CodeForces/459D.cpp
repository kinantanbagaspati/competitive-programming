#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 1048576;
int n, a[maxn], dp[maxn], segtree[maxn*2];
map<long long, long long> m;

void update(int idx, int val){
    idx += maxn;
    while(idx>0){
        segtree[idx] += val;
        idx /= 2;
    }
}
int query(int lo, int hi){
    int res = 0; lo += maxn; hi += maxn;
    while(hi >= lo){
        if(lo%2){
            res += segtree[lo];
        } lo = (lo+1)/2;
        if(!(hi%2)){
            res += segtree[hi];
        } hi = (hi-1)/2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        dp[i] = m[a[i]];
        m[a[i]]++;
    }
    long long ans = 0;
    m.clear();
    for(int i=n-1; i>=0; i--){
        ans += query(0, dp[i]-1);
        update(m[a[i]], 1);
        m[a[i]]++;
    }
    cout << ans << endl;
}
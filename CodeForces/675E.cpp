#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;
long long n, m, segtree[maxn*2], a[maxn], dp[maxn], ans;

void build(){
    for(int i=0; i<maxn; i++){
        if(i < n-1){
            cin >> a[i]; a[i]--;
        }
        segtree[maxn + i] = i;
    }
    /* cout << "a:";
    for(int i=0; i<8; i++){
        cout << ' ' << a[i];
    } cout << endl;*/
    for(int i=maxn-1; i>0; i--){
        segtree[i] = segtree[i*2];
        if(a[segtree[i*2]] < a[segtree[i*2+1]]){
            segtree[i] = segtree[i*2+1];
        }
    }
    /*
    for(int i=0; i<8; i++){
        cout << segtree[maxn + i] << ' ';
    } cout << endl;
    for(int i=0; i<4; i++){
        cout << segtree[maxn/2 + i] << ' ';
    } cout << endl;
    for(int i=0; i<2; i++){
        cout << segtree[maxn/4 + i] << ' ';
    } cout << endl;
    for(int i=0; i<1; i++){
        cout << segtree[maxn/8 + i] << ' ';
    } cout << endl;
    */
}
long long query(long long lo, long long hi){
    lo += maxn; hi += maxn;
    long long ret = n;
    while(lo <= hi){
        if(lo % 2 == 1 && a[ret] < a[segtree[lo]]){
            ret = segtree[lo];
        } lo = (lo+1)/2;
        if(hi % 2 == 0 && a[ret] < a[segtree[hi]]){
            ret = segtree[hi];
        } hi = (hi-1)/2;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    build();
    dp[n-2] = 1; ans = 1;
    
    for(int i=n-3; i>=0; i--){
        m = query(i+1, a[i]);
        dp[i] = dp[m] + (n-m-1) - (a[i] - m) * 2 + a[i] - i;
        //cout << "i m dp: " << i << " " << m << " - " << dp[i] << " " << dp[m] << endl;
        ans += dp[i];
    }
    cout << ans << endl;
}

/*
0 1 2 3 4
1 2 4 4
*/
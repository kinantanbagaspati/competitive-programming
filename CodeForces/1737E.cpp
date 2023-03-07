#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 1048576, mod = 1e9+7;
long long t, n, pw2[maxn], inv2[maxn];
long long dp[maxn], ans[maxn], temp;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pw2[0] = 1; inv2[0] = 1;
    for(int i=1; i<maxn; i++){
        pw2[i] = pw2[i-1] * 2 % mod;
        inv2[i] = inv2[i-1] * 500000004 % mod;
    }
    //cout << pw2[2] * inv2[2] % mod << endl;
    cin >> t;
    while(t--){
        cin >> n;
        if(n==1){
            cout << 1 << endl; continue;
        }
        for(int i=0; i<=n; i++){
            dp[i] = 0;
        }
        for(int i=n-1; i>=0; i--){
            dp[i] = (dp[i] + dp[i+1]*2) % mod;
            temp = (pw2[n-1-i] + mod - dp[i]) % mod;
            if(i == n-1){
                temp = temp * 2 % mod;
            }
            ans[i] = temp * pw2[(i-1)/2] % mod;
            if(i>0){
                dp[(i-1)/2] = (dp[(i-1)/2] + temp) % mod;
            }
        }
        for(int i=0; i<n; i++){
            cout << ans[i] * inv2[n-1] % mod << "\n";
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 300069, mod = 998244353;
long long t, n, dp[maxn], fac[maxn], invfac[maxn];
long long ans, cur, incur, pw2;

long long pangkat(long long a, long long b){
    a %= mod; b %= (mod-1);
    long long res = 1;
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}
long long inv(long long a){
    return pangkat(a, mod-2);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    dp[0] = 1; dp[1] = 1;
    fac[0] = 1; fac[1] = 1;
    invfac[0] = 1; invfac[1] = 1;
    for(int i=2; i<maxn; i++){
        dp[i] = (dp[i-1] + dp[i-2] * (i-1)) % mod;
        fac[i] = fac[i-1]*i%mod;
        invfac[i] = inv(fac[i]);
    }
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        incur = 1;
        pw2 = 1;
        for(int i=0; 4*i <= n; i++){
            // pilih bil cyc 4
            cur = invfac[n-4*i] * invfac[2*i] % mod;
            cur = cur * fac[n-2*i] % mod;
            // klmpkin cyc4
            cur = cur * incur % mod;
            cur = cur * pw2 % mod;
            // itung sisanya
            cur = cur * dp[n-4*i] % mod;

            ans = (ans + cur) % mod;
            incur = incur * (i*2+1) % mod;
            pw2 = pw2*2%mod;
        }
        cout << ans << endl;
    }
}

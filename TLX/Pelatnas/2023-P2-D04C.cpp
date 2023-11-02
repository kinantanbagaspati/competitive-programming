#include <bits/stdc++.h>
using namespace std;

const long long maxn = 300069, maxa = (1 << 30), mod = 998244353;
long long n, a[maxn], dp[maxn], sumDP[maxn];
long long chu[maxn], chd[maxn], szu, szd;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> a[0];
    dp[0] = 1; dp[1] = 0;
    sumDP[0] = 1; sumDP[1] = 1;
    chu[0] = 0; szu = 1; chd[0] = 0; szd = 1;

    for(int i=1; i<n; i++){
        //cout << dp[i] << endl;
        cin >> a[i];
        dp[i+1] = dp[i];
        // upper
        while(szu>1 && (a[chu[szu-1]] <= a[i])){
            szu--;
            dp[i+1] += (sumDP[chu[szu]] + mod - sumDP[chu[szu-1]]) % mod * (a[i] - a[chu[szu]]);
            dp[i+1] %= mod;
        }
        if(szu == 1 && (a[chu[0]] <= a[i])){
            szu--;
            dp[i+1] += sumDP[chu[0]] % mod * (a[i] - a[chu[0]]);
            dp[i+1] %= mod;
        }
        chu[szu] = i; szu++;

        // lower
        while(szd>1 && (a[chd[szd-1]] >= a[i])){
            szd--;
            dp[i+1] += (sumDP[chd[szd]] + mod - sumDP[chd[szd-1]]) % mod * (a[chd[szd]] - a[i]);
            dp[i+1] %= mod;
        }
        if(szd == 1 && (a[chd[0]] >= a[i])){
            szd--;
            dp[i+1] += sumDP[chd[0]] % mod * (a[chd[0]] - a[i]);
            dp[i+1] %= mod;
        }
        chd[szd] = i; szd++;

        sumDP[i+1] = (sumDP[i] + dp[i+1]) % mod;
    }
    cout << dp[n] << endl;
}
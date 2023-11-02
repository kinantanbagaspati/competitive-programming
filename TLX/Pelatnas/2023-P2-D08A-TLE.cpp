#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long n, m, k;
long long dp[maxn], ans[maxn];

int main() {
    cin >> n >> m >> k; n /= 2; m %= k;
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        dp[i] = dp[i-1]*m + k - (i+1)%2*dp[i/2];
        dp[i] %= k;
    }

    ans[0] = 1;
    for(int i=1; i<=n; i++){
        ans[i] = 0;
        for(int j=i; j>0; j--){
            ans[i] = (ans[i] + ans[i-j]*dp[j]) % k;
        }
    }

    cout << ans[n] << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long n, m, k;
long long dp[maxn][20], pw[20];

int main() {
    cin >> n >> m >> k; n /= 2; m %= k;
    pw[0] = 1; dp[0][0] = 1; dp[1][0] = m;
    for(int i=1; i<20; i++){
        pw[i] = pw[i-1]*2;
        dp[0][i] = 0;
        dp[1][i] = 0;
    }
    for(int i=2; i<=n; i++){
        dp[i][19] = 0;
        for(int j=18; j>=0; j--){
            dp[i][j] = 0;
            if(i >= pw[j]){
                dp[i][j] = m * dp[i-pw[j]][0] % k;
                dp[i][j] += m * dp[i-pw[j]][j];
                dp[i][j] %= k;
                dp[i][j] = (dp[i][j] + k - dp[i][j+1]) % k;
            }
        }
        /*
        cout << i << ": ";
        for(int j=0; j<=3; j++){
            cout << dp[i][j] << " ";
        }cout << endl;
        */
    }
    cout << dp[n][0] << endl;
    return 0;
}
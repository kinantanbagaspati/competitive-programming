#include <bits/stdc++.h>
using namespace std;

long long dp[5050][5050], n, x[5050], sum[5050];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    sum[0] = 0;
    for(int i=0; i<n; i++){
        cin >> x[i];
        sum[i+1] = sum[i] + x[i];
    }
    for(int i=0; i<n; i++){
        dp[0][i] = x[i];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i; j++){
            dp[i][j] = sum[j+i+1]-sum[j]-min(dp[i-1][j], dp[i-1][j+1]);
        }
    }
    cout << dp[n-1][0] << endl;
}

#include<bits/stdc++.h>
using namespace std;

const long long maxn = 262144;
long long n, d1, d2, dp[maxn][2], a[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> d1 >> d2;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    dp[0][0] = 0;
    dp[0][1] = a[0] * d2 - d1;
    for(int i=1; i<n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = dp[i][0] + a[i]*d2-d1;
        if(i>=2){
            dp[i][1] = max(dp[i][1], dp[i-2][1] + (a[i]+a[i-1])*d2 - d1);
        }
    }
    cout << max(dp[n-1][0], dp[n-1][1]) << endl;
}
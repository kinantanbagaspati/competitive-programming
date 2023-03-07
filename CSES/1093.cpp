#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
long long n, dp[100069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    dp[0] = 1;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=100000; j>=i; j--){
            dp[j] = (dp[j] + dp[j-i]) % mod;
        }
    }
    if(n*(n+1)%4 == 0){
        if(dp[n*(n+1)/4] %2){
            dp[n*(n+1)/4] += mod;
        }
        cout << dp[n*(n+1)/4]/2 << endl;
    }else{
        cout << 0 << endl;
    }

}

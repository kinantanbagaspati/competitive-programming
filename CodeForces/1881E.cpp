#include<bits/stdc++.h>
using namespace std;

long long t, n, dp[262144], a[262144];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n; dp[n] = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            dp[n-1-i] = dp[n-i] + 1;
            if(a[n-1-i] + n-i <= n){
                dp[n-1-i] = min(dp[n-1-i], dp[a[n-1-i] + n-i]);
            }
            //cout << dp[n-1-i] << "-";
        }
        cout << dp[0] << endl;
    }
}
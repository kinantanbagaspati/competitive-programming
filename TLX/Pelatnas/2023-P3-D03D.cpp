#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1048576;
long long n, a, b, c, dp[maxn], ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> a >> b >> c;
    dp[0] = 1;
    ans = 0;
    while(dp[ans] < n){
        ans++;
        dp[ans] = 0;
        if(ans>=a){
            dp[ans] += dp[ans-a];
        }
        if(ans>=b){
            dp[ans] += dp[ans-b];
        }
        if(ans>=c){
            dp[ans] += dp[ans-c];
        }
        dp[ans] = max(dp[ans-1], dp[ans]);
    }
    cout << ans << endl;
}
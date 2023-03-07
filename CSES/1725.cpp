#include <bits/stdc++.h>
using namespace std;

long long n, a, b;
double dp[2][1000], ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> a >> b;
    dp[0][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=6*n; j++){
            dp[(i+1)%2][j] = 0;
        }
        for(int j=0; j<=6*n; j++){
            for(int k=1; k<=6; k++){
                dp[(i+1)%2][j+k] += dp[i%2][j]/6;
            }
        }
    }
    ans = 0;
    for(int i=a; i<=b; i++){
        ans += dp[n%2][i];
    }
    cout << fixed << setprecision(6) << ans << endl;
}

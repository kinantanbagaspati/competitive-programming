#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, abc[131072][4];
long long dp[131072][8];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<3; i++){
            for(int j=0; j<n; j++){
                cin >> abc[j][i];
            }
        }
        for(int i=0; i<=n; i++){
            for(int j=0; j<8; j++){
                dp[i][j] = -1e18;
            }
        }
        dp[0][0] = 0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<8; j++){
                dp[i][j] = dp[i-1][j];
            }
            for(int j=0; j<3; j++){
                for(int k=0; k<8; k++){
                    if(((1<<j)&k) == 0){
                        dp[i][(1<<j)+k] = max(dp[i][(1<<j)+k], dp[i-1][k] + abc[i-1][j]);
                    }
                }
            }
        }
        cout << dp[n][7] << endl;
    }
}
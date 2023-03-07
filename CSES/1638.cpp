#include <bits/stdc++.h>
using namespace std;

long long dp[1069][1069];
long long mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    char c;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(min(i,j) == 0){
                dp[i][j] = 0;
            }else{
                cin >> c;
                if(c == '*'){dp[i][j] = 0;}
                else if(i==1 && j==1){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = (dp[i][j-1] + dp[i-1][j])%mod;
                }
            }
        }
    }
    cout << dp[n][n] << endl;
}

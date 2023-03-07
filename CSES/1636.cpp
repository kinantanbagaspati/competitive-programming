#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[100][1000069];
int n, x, c[100];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> c[i];
        if(i == 0){
            for(int j=0; j<=x; j++){
                dp[i][j] = (j % c[i] == 0);
            }
        }else{
            for(int j=0; j<=x; j++){
                dp[i][j] = dp[i-1][j];
                if(j >= c[i]){
                    dp[i][j] = (dp[i][j] + dp[i][j-c[i]])%mod;
                }
            }
        }
    }
    cout << dp[n-1][x] << endl;
}

#include <bits/stdc++.h>
using namespace std;

long long dp[505][505], a, b;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> a >> b;
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i==j){dp[i][j] = 0;}
            else{
                dp[i][j] = 1e9;
                for(int k=1; k<i; k++){
                    dp[i][j] = min(1+dp[k][j]+dp[i-k][j], dp[i][j]);
                }
                for(int k=1; k<j; k++){
                    dp[i][j] = min(1+dp[i][k]+dp[i][j-k], dp[i][j]);
                }
            }
        }
    }
    cout << dp[a][b] << endl;
}

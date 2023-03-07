#include <bits/stdc++.h>
using namespace std;

long long dp[1069][1069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, q;
    cin >> n >> q;
    char c;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(min(i,j)==0){
                dp[i][j] = 0;
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
                cin >> c;
                if(c == '*'){dp[i][j]++;}
            }
        }
    }
    long long a1, b1, a2, b2;
    while(q--){
        cin >> a1 >> b1 >> a2 >> b2;
        cout << dp[a2][b2] - dp[a2][b1-1] - dp[a1-1][b2] + dp[a1-1][b1-1] << endl;
    }
}

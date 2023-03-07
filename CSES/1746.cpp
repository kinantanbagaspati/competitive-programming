#include <bits/stdc++.h>
using namespace std;

long long dp[100069][101], mod=1000000007;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m, x;
    cin >> n >> m;
    cin >> x;
    for(int j=1; j<=m; j++){dp[0][j]=(x==0);}
    dp[0][x] = 1;
    for(int i=1; i<n; i++){
        cin >> x;
        if(x==0){
            for(int j=1; j<=m; j++){
                dp[i][j] = dp[i-1][j];
                if(j>1){dp[i][j] += dp[i-1][j-1];}
                dp[i][j]-=mod*(dp[i][j]>=mod);
                if(j<m){dp[i][j] += dp[i-1][j+1];}
                dp[i][j]-=mod*(dp[i][j]>=mod);
            }
        }else{
            for(int j=1; j<=m; j++){dp[i][j]=0;}
            dp[i][x]=dp[i-1][x];
            if(x>1){dp[i][x] += dp[i-1][x-1];}
            dp[i][x]-=mod*(dp[i][x]>=mod);
            if(x<m){dp[i][x] += dp[i-1][x+1];}
            dp[i][x]-=mod*(dp[i][x]>=mod);
        }
    }
    long long ans = 0;
    for(int j=1; j<=m; j++){
        ans += dp[n-1][j];
    }
    cout << ans%mod << endl;
}

#include<bits/stdc++.h>
using namespace std;

const long long maxn = 1024;
long long t, n, m, dp[maxn][maxn], ans;

long long dfs(long long x, long long y){
    if(dp[x][y] == 0){
        return 0;
    }
    long long res = dp[x][y]; dp[x][y] = 0;
    if(x && dp[x-1][y]){
        res += dfs(x-1, y);
    }
    if(x < n-1 && dp[x+1][y]){
        res += dfs(x+1, y);
    }
    if(y && dp[x][y-1]){
        res += dfs(x, y-1);
    }
    if(y < m-1 && dp[x][y+1]){
        res += dfs(x, y+1);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m; ans = 0;
        for(long long i=0; i<n; i++){
            for(long long j=0; j<m; j++){
                cin >> dp[i][j];
            }
        }
        for(long long i=0; i<n; i++){
            for(long long j=0; j<m; j++){
                ans = max(dfs(i, j), ans);
            }
        }
        cout << ans << endl;
    }
}
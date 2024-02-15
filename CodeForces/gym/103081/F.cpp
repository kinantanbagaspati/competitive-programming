#include<bits/stdc++.h>
using namespace std;

const long long maxn = 2048;
long long r, n, m, dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> r >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=min((int)r, i-1); j++){

        }
    }
    cout << dp[n][r] << endl;
}
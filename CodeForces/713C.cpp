#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 3003;
long long n, a[maxn], srt[maxn];
long long dp[maxn][maxn], cur, ans = 1e18;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i]; a[i] -= i; srt[i] = a[i];
        //cout << a[i] << ' ';
    } //cout << endl << endl;
    sort(srt, srt+n);
    for(int i=0; i<n; i++){
        dp[0][i] = abs(a[0] - srt[i]);
        //cout << dp[0][i] << ' ';
    } //cout << endl;
    for(int i=1; i<n; i++){
        cur = dp[i-1][0];
        dp[i][0] = abs(a[i] - srt[0]) + cur;
        //cout << dp[i][0];
        for(int j=1; j<n; j++){
            cur = min(cur, dp[i-1][j]);
            dp[i][j] = abs(a[i] - srt[j]) + cur;
            //cout << ' ' << dp[i][j];
        } //cout << endl;
    }
    for(int i=0; i<n; i++){
        ans = min(ans, dp[n-1][i]);
    }
    cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 102400, maxk = 320;
int n, k, p, q, ans, dp[maxk][maxn], a[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=1; i<maxk; i++){
        for(int j=n-1; j>=0; j--){
            if(j + a[j] + i < n){
                dp[i][j] = dp[i][j+a[j]+i] + 1;
            }else{
                dp[i][j] = 1;
            }
        }
    }
    cin >> q;
    while(q--){
        cin >> p >> k; p--;
        if(k < maxk){
            //cout << k << " " << p << ": ";
            cout << dp[k][p] << endl;
        }else{
            ans = 0;
            while(p<n){
                p += a[p] + k; ans++;
            }
            cout << ans << endl;
        }
    }
}
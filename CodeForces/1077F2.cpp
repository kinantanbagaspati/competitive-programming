#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 5050;
long long n, k, x, ans = -1;
long long a[maxn], dp[maxn][maxn];
multiset<long long> ms;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k >> x;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        for(int j=1; j<=n; j++){
            dp[j][i] = -1;
        }
    }
    dp[0][0] = 0;
    for(int i=1; i<=x; i++){
        for(int j=i; j<=min(k*i, n); j++){
            if(j-1 <= (k-1)*i){
                ms.insert(-dp[i-1][j-1]);
            }
            if(j >= i+k){
                ms.erase(ms.lower_bound(-dp[i-1][j-k-1]));
            }
            dp[i][j] = max(dp[i][j], a[j] - *(ms.begin()));
        }
    }
    for(int i=n; i>max(0LL, n-k); i--){
        ans = max(dp[x][i], ans);
    }
    cout << ans << endl;
}
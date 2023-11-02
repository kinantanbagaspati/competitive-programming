#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;
long long n, k, c, d;
long long mx11, mx12, mx13, mx2, mx3, temp;
long long dp[2][10];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<10; i++){
        dp[0][i] = -1e18;
        dp[1][i] = -1e18;
    }
    dp[1][0] = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            dp[i%2][j] = dp[(i+1)%2][j];
        }
        cin >> k;
        mx11 = -1e18, mx12 = -1e18; mx13 = -1e18; mx2 = -1e18; mx3 = -1e18;
        while(k--){
            cin >> c >> d;
            if(c == 3){
                mx3 = max(d, mx3);
            }else if(c == 2){
                mx2 = max(d, mx2);
            }else{
                if(d > mx13){
                    mx13 = d;
                }
                if(mx13 > mx12){
                    temp = mx13; mx13 = mx12; mx12 = temp;
                }
                if(mx12 > mx11){
                    temp = mx12; mx12 = mx11; mx11 = temp;
                }
            }
        }
        //nambah 3 bil
        if(mx13 > 0){
            for(int j=3; j<10; j++){
                dp[i%2][j] = max(dp[(i+1)%2][j-3]+mx11+mx12+mx13, dp[i%2][j]);
            }
            for(int j=7; j<10; j++){
                dp[i%2][j-7] = max(dp[(i+1)%2][j]+2*mx11+mx12+mx13, dp[i%2][j-7]);
            }
        }
        // nambah 2 bil
        if(mx12 > 0 || mx2 > 0){
            for(int j=2; j<10; j++){
                dp[i%2][j] = max(dp[(i+1)%2][j-2]+mx11+max(mx12,mx2), dp[i%2][j]);
            }
            for(int j=8; j<10; j++){
                dp[i%2][j-8] = max(
                    dp[(i+1)%2][j]+mx11+max(mx12,mx2)+max(max(mx12,mx2),mx11), 
                    dp[i%2][j-8]
                );
            }
        }
        // nambah 1 bil
        for(int j=1; j<10; j++){
            dp[i%2][j] = max(dp[(i+1)%2][j-1]+max(max(mx2,mx3),mx11), dp[i%2][j]);
        }
        dp[i%2][0] = max(dp[(i+1)%2][9] + max(max(mx2,mx3),mx11)*2, dp[i%2][0]);
    }
    long long ans = 0;
    for(int i=0; i<10; i++){
        ans = max(dp[(n-1)%2][i], ans);
    }
    cout << ans << endl;
}
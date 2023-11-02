#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long n, m, b[32], dp[1048576][2];
long long curm, curn, nxt;
long long to[32][262144];
pll a[262144];
vector<long long> ans[32];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i].first; a[i].second = i+1;
    }
    sort(a, a+n);
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            to[i][j] = j + (b[i] + a[j].first - 1) / a[j].first;
            //cout << to[i][j] << " ";
        }//cout << endl;
        for(int j=n-2; j>=0; j--){
            to[i][j] = min(to[i][j], to[i][j+1]);
            //cout << to[i][j] << " ";
        }//cout << endl;
    }
    dp[0][0] = 0;
    for(int i=1; i<(1<<m); i++){
        dp[i][0] = 1e18;
        for(int j=0; j<m; j++){
            if(((1<<j) & i) > 0){
                long long idx = dp[i-(1<<j)][0];
                if(idx < n){
                    if(to[j][idx] < dp[i][0]){
                        dp[i][0] = to[j][idx];
                        dp[i][1] = j;
                    }
                }
            }
        }
    }


    if(dp[(1<<m)-1][0] > n){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        curm = (1<<m)-1;
        while(curm > 0){
            nxt = curm - (1 << dp[curm][1]);
            for(int i=dp[nxt][0]; i<dp[curm][0]; i++){
                ans[dp[curm][1]].push_back(a[i].second);
            }
            curm = nxt;
        }
        for(int i=0; i<m; i++){
            cout << ans[i].size();
            for(int j=0; j<ans[i].size(); j++){
                cout << " " << ans[i][j];
            }cout << endl;
        }    
    }
}
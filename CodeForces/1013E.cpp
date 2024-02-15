#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 5050;
int n, dp[maxn][4][maxn/2], a[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        for(int j=0; j<4; j++){
            for(int k=0; k<=(n+1)/2; k++){
                dp[i][j][k] = 2e9;
            }
            if(j!=2){
                dp[i][j][0] = 0;
            }
        }
    }
    dp[0][0][1] = 0;
    for(int i=1; i<n; i++){
        //cout << "i = " << i << endl;
        // puncak di ujung
        //cout << "0:";
        for(int j=1; j<=i/2+1; j++){
            dp[i][0][j] = min(
                dp[i-1][1][j-1] + max(0, dp[i-1][2][j-1]+1-a[i]),
                dp[i-1][3][j-1] + max(0, a[i-1]+1-a[i]) 
            );
            //cout << ' ' << dp[i][0][j];
        }
        //cout << endl;
        // puncak kedua dr ujung
        //cout << "1:";
        for(int j=1; j<=(i+1)/2; j++){
            dp[i][1][j] = dp[i-1][0][j] + max(0, a[i]+1-a[i-1]);
            dp[i][2][j] = min(a[i-1]-1, a[i]);
            //cout << ' ' << dp[i][1][j] << "-" << dp[i][2][j];
        } 
        //cout << endl;
        // puncak ga deket dari ujung
        //cout << "3:";
        for(int j=1; j<=i/2; j++){
            dp[i][3][j] = min(dp[i-1][3][j], dp[i-1][1][j]);
            //cout << ' ' << dp[i][3][j];
        }
        //cout << endl << endl;
    }
    for(int i=1; i<=(n+1)/2; i++){
        cout << min({dp[n-1][0][i], dp[n-1][1][i], dp[n-1][3][i]}) << ' ';
    } cout << endl;
}
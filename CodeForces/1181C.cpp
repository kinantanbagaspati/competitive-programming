#include<bits/stdc++.h>
using namespace std;

const int maxn = 1048;
int n, m, ans = 0, cur;
char board[maxn][maxn];
pair<string, pair<int, int>> dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<m; i++){
        cur = 1;
        for(int j=0; j<n-1; j++){
            //cout << j << " " << cur << " " << board[j][i] << board[j+1][i] << endl;
            if(board[j+1][i] == board[j][i]){
                cur++;
            }else if(j+cur<n && j-2*cur+1>=0){
                bool isFlag = (board[j-cur][i] != board[j][i]);
                for(int k=1; k<cur; k++){
                    isFlag = (board[j+1+k][i] == board[j+1][i]) && (board[j-cur-k][i] == board[j-cur][i]) && isFlag;
                }
                //cout << j << " " << isFlag << endl;
                if(isFlag){
                    dp[j][i] = {"   ", {cur, 1}};
                    dp[j][i].first[0] = board[j-cur][i];
                    dp[j][i].first[1] = board[j][i];
                    dp[j][i].first[2] = board[j+1][i];
                    if(i>0 && dp[j][i-1].first == dp[j][i].first){
                        if(dp[j][i-1].second.first == dp[j][i].second.first){
                            dp[j][i].second.second += dp[j][i-1].second.second;
                        }
                    }
                    ans += dp[j][i].second.second;
                }
                cur = 1;
            }else{
                cur = 1;
            }
        }
    }
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1024;
long long t, n, ans;
string board[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> board[i];
        }
        ans = 0;
        for(int i=0; i<n/2; i++){
            for(int j=0; j<(n+1)/2; j++){
                char c = max(
                    max(board[i][j], board[n-1-i][n-1-j]), 
                    max(board[j][n-1-i], board[n-1-j][i])
                );
                ans += c - board[i][j];
                ans += c - board[j][n-1-i];
                ans += c - board[n-1-i][n-1-j];
                ans += c - board[n-1-j][i];
            }
        }
        cout << ans << endl;
    }
}
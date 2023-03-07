#include <bits/stdc++.h>
using namespace std;

const int maxn = 1024;
int n, m, ans;
bool border;
string board[maxn];

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> board[i];
    }
    ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            border = false;
            if(i>0 && board[i-1][j] == '-'){border = true;}
            if(j>0 && board[i][j-1] == '-'){border = true;}
            if(i<n-1 && board[i+1][j] == '-'){border = true;}
            if(j<m-1 && board[i][j+1] == '-'){border = true;}
            ans += border && (board[i][j] == '+');
        }
    }
    cout << ans << endl;
}

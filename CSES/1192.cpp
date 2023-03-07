#include <bits/stdc++.h>
using namespace std;

string board[1069];
long long n, m;

void dfs(long long x, long long y){
    board[x][y] = '#';
    if(x>0 && (board[x-1][y] == '.')){dfs(x-1,y);}
    if(x<n-1 && (board[x+1][y] == '.')){dfs(x+1,y);}
    if(y>0 && (board[x][y-1] == '.')){dfs(x,y-1);}
    if(y<m-1 && (board[x][y+1] == '.')){dfs(x,y+1);}
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> board[i];
    }
    long long ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == '.'){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
}

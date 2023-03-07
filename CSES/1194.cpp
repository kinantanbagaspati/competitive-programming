#include <bits/stdc++.h>
using namespace std;

char board[1069][1069], pre[1069][1069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m;
    cin >> n >> m;
    queue<pair<long long, long long> > q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] == 'M'){
                q.push({i,j});
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'A'){
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        pair<long long, long long> p = q.front();
        long long a = p.first;
        long long b = p.second;
        q.pop();
        if(a>0 && board[a-1][b] == '.'){
            q.push({a-1,b});
            board[a-1][b] = board[a][b];
            pre[a-1][b] = 'L';
            if(board[a][b] < 96){board[a-1][b] += 32;}
        }
        if(a<n-1 && board[a+1][b] == '.'){
            q.push({a+1,b});
            board[a+1][b] = board[a][b];
            pre[a+1][b] = 'R';
            if(board[a][b] < 96){board[a+1][b] += 32;}
        }
        if(b>0 && board[a][b-1] == '.'){
            q.push({a,b-1});
            board[a][b-1] = board[a][b];
            pre[a][b-1] = 'U';
            if(board[a][b] < 96){board[a][b-1] += 32;}
        }
        if(b<m-1 && board[a][b+1] == '.'){
            q.push({a,b+1});
            board[a][b+1] = board[a][b];
            pre[a][b+1] = 'D';
            if(board[a][b] < 96){board[a][b+1] += 32;}
        }
    }
    bool found = false;
    vector<char> ans;
    for(int i=0; !found && i<n; i++){
        for(int j=0; !found && j<m; j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(board[i][j] == 'A' || board[i][j] == 'a'){
                    found = true;
                    long long curx = i, cury = j;
                    while(board[curx][cury] == 'a'){
                        ans.push_back(pre[curx][cury]);
                        if(pre[curx][cury] == 'L'){curx++;}
                        else if(pre[curx][cury] == 'U'){cury++;}
                        else if(pre[curx][cury] == 'R'){curx--;}
                        else if(pre[curx][cury] == 'D'){cury--;}
                    }
                }
            }
        }
    }
    if(found){
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for(int i=ans.size()-1; i>=0; i--){
            if(ans[i] == 'L'){cout << 'U';}
            if(ans[i] == 'U'){cout << 'L';}
            if(ans[i] == 'R'){cout << 'D';}
            if(ans[i] == 'D'){cout << 'R';}
        }cout << endl;
    }else{
        cout << "NO" << endl;
    }
}

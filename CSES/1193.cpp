#include <bits/stdc++.h>
using namespace std;

long long n, m;
string board[1069], ans, backtrack[1069][1069];

void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            backtrack[i][j] = "";
        }
    }
}

void consolve(long long x, long long y){
    while(backtrack[x][y] != ""){
        ans += backtrack[x][y];
        if(backtrack[x][y] == "U"){
            x++;
        }else if(backtrack[x][y] == "D"){
            x--;
        }else if(backtrack[x][y] == "L"){
            y++;
        }else{
            y--;
        }
    }
    for(int i=0; i<ans.length()/2; i++){
        char temp = ans[i];
        ans[i] = ans[ans.length()-1-i];
        ans[ans.length()-1-i] = temp;
    }
}

bool bfs(long long x, long long y){
    init();
    queue<pair<long long, long long> > q;
    q.push({x,y});
    board[x][y] = '#';
    while(!q.empty()){
        long long a = q.front().first;
        long long b = q.front().second;
        q.pop();
        if(a>0 && board[a-1][b] != '#'){
            backtrack[a-1][b] = "U";

            if(board[a-1][b] == 'B'){
                consolve(a-1,b);
                return true;
            }
            board[a-1][b] = '#';

            q.push({a-1,b});
        }
        if(a<n-1 && board[a+1][b] != '#'){
            backtrack[a+1][b] = "D";

            if(board[a+1][b] == 'B'){
                consolve(a+1,b);
                return true;
            }
            board[a+1][b] = '#';


            q.push({a+1,b});
        }
        if(b>0 && (board[a][b-1] != '#')){
            backtrack[a][b-1] = "L";

            if(board[a][b-1] == 'B'){
                consolve(a,b-1);
                return true;
            }
            board[a][b-1] = '#';

            q.push({a,b-1});
        }
        if(b<m-1 && board[a][b+1] != '#'){
            backtrack[a][b+1] = "R";

            if(board[a][b+1] == 'B'){
                consolve(a,b+1);
                return true;
            }
            board[a][b+1] = '#';

            q.push({a,b+1});
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> board[i];
    }
    bool res;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 'A'){
                res = bfs(i,j);
            }
        }
    }
    if(res){
        cout << "YES" << endl;
        cout << ans.length() << endl;
        cout << ans << endl;
    }else{
        cout << "NO" << endl;
    }
}

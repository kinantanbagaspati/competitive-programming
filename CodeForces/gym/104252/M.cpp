#include<bits/stdc++.h>
using namespace std;

int r, c, first = -1;
string nut;
char ch;
bool board[3][1024][128];

bool dfs(int id, int row, int col){
    if(row == r-1) return true;
    board[id][row][col] = true;
    if(row > 0 && !board[id][row-1][col] && dfs(id, row-1, col)) return true;
    if(!board[id][row][(col+c-1)%c] && dfs(id, row, (col+c-1)%c)) return true;
    if(!board[id][row][(col+1)%c] && dfs(id, row, (col+1)%c)) return true;
    if(!board[id][row+1][col] && dfs(id, row+1, col)) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> r >> c;
    cin >> nut;
    for(int i=0; i<c; i++){
        if(nut[i] == '1' && first < 0){
            first = i;
        }
    }
    if(first < 0){
        cout << "Y" << endl; return 0;
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> ch;
            board[0][i][j] = (ch == '1');
            board[1][i][j] = (ch == '1');
            board[2][i][j] = (ch == '1');
        }
        for(int j=0; j<c; j++){
            if(nut[j] == '1'){
                for(int k=0; k<c; k++){
                    board[1][i][k] = board[1][i][k] || board[0][i][(k+j-first)%c];
                    board[2][i][k] = board[2][i][k] || board[0][i][(k+c+first-j)%c];
                }
            }
        }
    }

    /*for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << board[1][2]
        }
    }*/

    bool nemu = false;
    for(int i=1; i<=2 && !nemu; i++){
        for(int j=0; j<c && !nemu; j++){
            if(!board[i][0][j]){
                nemu = dfs(i, 0, j) || nemu;
            }
        }
    }
    if(nemu){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }
}
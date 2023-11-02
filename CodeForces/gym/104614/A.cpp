#include <bits/stdc++.h>
using namespace std;

long long c, r, finax, finay, finbx, finby;
long long ax, ay, bx, by, eax, eay, ebx, eby;
bool mazeA[64][64][4], mazeB[64][64][4], vis[64][64][64][64];
long long ans[64][64][64][64], temp, x, y;
char dirA, dirB;
map<char, int> arah;
queue<int> qax, qay, qbx, qby;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> c >> r >> finax; finay = 0;
    arah['N'] = 0;
    arah['E'] = 1;
    arah['S'] = 2;
    arah['W'] = 3;
    cin >> ax >> ay >> dirA;
    cin >> bx >> by >> dirB;
    
    cin >> temp;
    while(temp--){
        cin >> x >> y;
        mazeA[x][y][0] = true;
        mazeA[x][y+1][2] = true;
    }
    cin >> temp;
    while(temp--){
        cin >> x >> y;
        mazeA[x][y][1] = true;
        mazeA[x+1][y][3] = true;
    }
    for(int i=1; i<=r; i++){
        mazeA[i][c][0] = true;
        mazeA[i][1][2] = true;
    }
    for(int i=1; i<=c; i++){
        mazeA[1][i][3] = true;
        mazeA[r][i][1] = true;
    }

    long long dif = (arah[dirB] + 4 - arah[dirA]) % 4;
    if(dif == 0){
        finbx = finax; finby = finay;
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                for(int k=0; k<4; k++){
                    mazeB[i][j]
                }
            }
        }
    }else if(dif == 1){

    }
}

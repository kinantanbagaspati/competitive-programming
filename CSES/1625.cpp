#include <bits/stdc++.h>
using namespace std;

vector<string> path;
string cur;
long long idx, curx, cury;
bool vis[7][7];

void init(){
    cur = "";
    for(int i=0; i<48; i++){cur += " ";}
    idx = 0;
    curx = 0;
    cury = 0;
    for(int i=0; i<49; i++){vis[i/7][i%7] = false;}
}
void dfs(){
    cout << idx << endl;
    if(idx == 48){
        if(curx == 6 && cury == 0){
            path.push_back(cur);
        }
        return;
    }
    if(curx>0 && !vis[curx-1][cury]){
        cur[idx] = 'U';
        curx--;
        idx++;
        vis[curx][cury] = true;
        dfs();
        vis[curx][cury] = false;
        idx--;
        curx++;
    }
    if(curx<6 && !vis[curx+1][cury]){
        cur[idx] = 'D';
        curx++;
        idx++;
        vis[curx][cury] = true;
        dfs();
        vis[curx][cury] = false;
        idx--;
        curx--;
    }
    if(cury>0 && !vis[curx][cury-1]){
        cur[idx] = 'L';
        cury--;
        idx++;
        vis[curx][cury] = true;
        dfs();
        vis[curx][cury] = false;
        idx--;
        cury++;
    }
    if(cury<6 && !vis[curx][cury+1]){
        cur[idx] = 'R';
        cury++;
        idx++;
        vis[curx][cury] = true;
        dfs();
        vis[curx][cury] = false;
        idx--;
        cury--;
    }

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    dfs();
    cout << path.size() << endl;

}

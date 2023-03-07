#include <bits/stdc++.h>
using namespace std;

long long n, q;
long long to[30][200069], id[200069], depth[200069], curId = 1;
long long rot[200069], circum[200069];

void dfs(long long node){
    if(to[0][node] == node){
        id[node] = curId;
        depth[node] = 0;
        rot[node] = 0;
        circum[curId] = 1;
        curId++;
    }// Udah gaada self cycle
    id[node] = 0;
    if(id[to[0][node]] < 0){
        dfs(to[0][node]);
    }
    if(id[node] > 0){
        return;
    }
    if(id[to[0][node]]==0){ // ketemu cycle
        long long cur = to[0][node];
        long long idx = 0;
        while(cur != node){
            id[cur] = curId;
            depth[cur] = 0;
            rot[cur] = idx;
            idx++;
            cur = to[0][cur];
        }
        id[node] = curId;
        depth[node] = 0;
        rot[node] = idx;
        circum[curId] = idx+1;
        curId++;
    }else{
        id[node] = id[to[0][node]];
        depth[node] = depth[to[0][node]]+1;
    }
}

void debug(){
    for(int i=1; i<=n; i++){
        cout << "id: " << id[i] << ", depth: " << depth[i] << ", rot: " << rot[i] << endl;
        for(int j=0; j<5; j++){
            cout << to[j][i] << " ";
        }cout << endl;
    }
}

void binlift(){
    for(int i=1; i<30; i++){
        for(int j=1; j<=n; j++){
            long long k = to[i-1][j];
            to[i][j] = to[i-1][k];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> to[0][i];
        /*
        id[i] = -1;
        depth[i] = -1;
        */
    }
    /*
    for(int i=1; i<=n; i++){
        if(id[i] < 0){
            dfs(i);
        }
    }
    */
    binlift();
    //debug();
    long long a, b;
    while(q--){
        cin >> a >> b;
        for(int i=0; b>0; i++){
            if(b%2){
                a = to[i][a];
            }
            b /= 2;
        }
        cout << a << endl;
    }
}

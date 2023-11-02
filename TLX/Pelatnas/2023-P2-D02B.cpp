#include <bits/stdc++.h>
using namespace std;

const int maxn = 524288;
int n, parent[maxn], nbFalse[2][maxn];
//nbFalse[0][i]=0 kalau pemain pertama kalah pas mulai dari i tapi gaboleh ambil parent i
//nbFalse[1][i]=0 kalau pemain pertama kalah pas mulai dari parent i tapi gaboleh ambil i
vector<int> children[maxn];

void dfsDown(int node){
    nbFalse[0][node] = 0;
    for(int i=0; i<children[node].size(); i++){
        int to = children[node][i];
        dfsDown(to);
        nbFalse[0][node] += (nbFalse[0][to] == 0);
    }
}

void dfsUp(int node){
    nbFalse[1][node] = nbFalse[0][parent[node]] - (nbFalse[0][node] == 0) + (nbFalse[1][parent[node]] == 0);
    for(int i=0; i<children[node].size(); i++){
        dfsUp(children[node][i]);
    }
}

int main(){
    cin >> n; parent[1] = 0;
    for(int i=2; i<=n; i++){
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }
    dfsDown(1);
    nbFalse[1][1] = 1;
    for(int i=0; i<children[1].size(); i++){
        dfsUp(children[1][i]);
    }
    /*
    for(int i=1; i<=n; i++){
        cout << i << ": " << nbFalse[0][i] << " " << nbFalse[1][i] << endl;
    }
    */

    if(nbFalse[0][1] == 0){
        cout << "1 ";
    }
    for(int i=2; i<=n; i++){
        if(nbFalse[0][i] == 0 && nbFalse[1][i] > 0){
            cout << i << " ";
        }
    }cout << endl;
}
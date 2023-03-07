#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 2048;
int hortot, vertot;

// tree
bool isHor[maxn];
int nbchild[maxn], nbnode=1;
vector<int> child[maxn];

// buat crt
int hor[maxn], ver[maxn], horcon[maxn], vercon[maxn], fpb, kpk;

// buat gambar
char board[1024][1024];

void dfsInput(int par, int node){
    isHor[node] = !isHor[par];
    cin >> nbchild[node];
    for(int i=0; i<nbchild[node]; i++){
        nbnode++;
        child[node].push_back(nbnode);
        dfsInput(node, nbnode);
    }
    if(!nbchild[node]){
        cin >> hor[node] >> ver[node];
    }
}

bool dfsNgitung(int node){
    if(!nbchild[node]){
        horcon[node] = hor[node]+1; vercon[node] = ver[node]+1;
        return (horcon[node] < hortot) && (vercon[node] < vertot);
    }
    if(!dfsNgitung(child[node][0])){
        return false;
    }
    // crt
    horcon[node] = horcon[child[node][0]]; // crt
    hor[node] = hor[child[node][0]]; // kpk
    vercon[node] = vercon[child[node][0]]; // crt
    ver[node] = ver[child[node][0]]; // kpk

    if(isHor[node]){
        for(int i=1; i<nbchild[node]; i++){
            int to = child[node][i];
            if(!dfsNgitung(to)){
                return false;
            }

            fpb = __gcd(ver[node], ver[to]);
            while(vercon[node] <= vertot && vercon[node] % ver[to] != vercon[to] % ver[to]){
                vercon[node] += ver[node];
                horcon[node] += hor[node];
            }
            if(vercon[node] > vertot || horcon[node] > hortot){
                return false;
            }

            hor[node] +=
            ver[node] = ver[node] / fpb * ver[to];
        }

        ver[node] = kpk; vercon[node] = crt;
        hor[node] = 0; horcon[node] = 0;
        for(int i=0; )

    }else{
        // crt
        crt = hor[child[node][0]] + horcon[child[node][0]];
        kpk = hor[child[node][0]];

        for(int i=1; i<nbchild[node]; i++){
            int to = child[node][i];
            if(!dfsNgitung(to)){
                return false;
            }

            fpb = __gcd(kpk, hor[to]);
            if(crt % kpk % fpb != horcon[to] % fpb){
                return false; // gabisa di crt
            }

            while(crt % hor[to] != horcon[to] % hor[to]){
                crt += kpk;
            }
            kpk = kpk / fpb * hor[to];
            if(crt >= hortot){
                return false; // kelebihan
            }
        }

        // update mul
        return (hor[node] + horcon[node] < hortot) && (ver[node] + vercon[node] < vertot);
    }
    mul[node] = 1;
    // update mul
    horcon[node] = !isHor[node];
    vercon[node] = isHor[node];
    if(isHor[node]){
        hor[node] = 0; ver[node] = kpk;
        horcon[node] = 0; vercon[node] = crt%kpk;
    }else{
        hor[node] = kpk; ver[node] = 0;

    }
    for(int i=0; i<nbchild[node]; i++){
        int to = child[node][i];
        if(isHor[node]){
            mul[to] = (crt - vercon[to]) / ver[to];
        }else{

        }
    }

    return true;
}

void dfsGambar(int node, int curmul, int horoff, int veroff){

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> hortot >> vertot;
    isHor[0] = false;
    dfsInput(0, 1);
    bool hasil = dfsNgitung(1);
    if(hasil){
        for(int i=0; i<=vertot; i++){
            for(int j=0; j<=hortot; j++){
                board[i][j] = '*';
            }
        }
        dfsGambar(1, 1, 1, 1);
        for(int i=0; i<=vertot; i++){
            for(int j=0; j<=hortot; j++){
                cout << board[i][j];
            }cout << endl;
        }
    }else{
        cout << "impossible" << endl;
    }
}

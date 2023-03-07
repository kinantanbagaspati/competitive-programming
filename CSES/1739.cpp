#include <bits/stdc++.h>
using namespace std;

const long long maxn = 1024;
long long segtree[2*maxn][2*maxn], n, q;

void update(long long x, long long y){
    for(int i=x; i>0; i/=2){
        if(i<maxn){
            segtree[i][y] = segtree[2*i][y] + segtree[2*i+1][y];
        }
        for(int j=y/2; j>0; j/=2){
            segtree[i][j] = segtree[i][2*j] + segtree[i][2*j+1];
        }
    }
}

long long query(long long lox, long long loy, long long hix, long long hiy){
    long long ret = 0;
    vector<long long> idxi, idxj;
    while(lox <= hix){
        if(lox%2){
            idxi.push_back(lox);
        }
        lox = (lox+1)/2;
        if(!(hix%2)){
            idxi.push_back(hix);
        }
        hix = (hix-1)/2;
    }
    while(loy <= hiy){
        if(loy%2){
            idxj.push_back(loy);
        }
        loy = (loy+1)/2;
        if(!(hiy%2)){
            idxj.push_back(hiy);
        }
        hiy = (hiy-1)/2;
    }
    for(int i=0; i<idxi.size(); i++){
        for(int j=0; j<idxj.size(); j++){
            ret += segtree[idxi[i]][idxj[j]];
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    char c;
    for(int i=maxn; i < maxn+n; i++){
        for(int j=maxn; j < maxn+n; j++){
            cin >> c;
            segtree[i][j] = (c == '*');
            update(i, j);
        }
    }
    long long t, lox, hix, loy, hiy, x, y;
    while(q--){
        cin >> t;
        if(t == 1){
            cin >> x >> y;
            x += maxn-1; y += maxn-1;
            segtree[x][y] = !segtree[x][y];
            update(x, y);
        }else{
            cin >> lox >> loy >> hix >> hiy;
            lox += maxn-1;
            loy += maxn-1;
            hix += maxn-1;
            hiy += maxn-1;
            cout << query(lox, loy, hix, hiy) << endl;
        }
    }
}

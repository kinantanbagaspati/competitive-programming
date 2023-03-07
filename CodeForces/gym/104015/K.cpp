#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 1024;

long long n, m, q, u, v;
long long ans, mati;
bool board[maxn][maxn];

long long getKananBawah(int x, int y, bool kanan){
    int res = 1;
    if(kanan){y++;}
    else{x++;}
    kanan = !kanan;
    while(x<=n && y<=m && !board[x][y]){
        res++;
        if(kanan){y++;}
        else{x++;}
        kanan = !kanan;
    }
    return res;
}
long long getKiriAtas(int x, int y, bool kiri){
    int res = 1;
    if(kiri){y--;}
    else{x--;}
    kiri = !kiri;
    while(x > 0 && y > 0 && !board[x][y]){
        res++;
        if(kiri){y--;}
        else{x--;}
        kiri = !kiri;
    }
    return res;
}

void flip(int x, int y){
    if(board[x][y]){ // bakal nambah
        ans += getKiriAtas(x, y, true) * getKananBawah(x, y, false);
        ans += getKiriAtas(x, y, false) * getKananBawah(x, y, true);
    }else{ // bakal ngurang
        ans -= getKiriAtas(x, y, true) * getKananBawah(x, y, false);
        ans -= getKiriAtas(x, y, false) * getKananBawah(x, y, true);
    }
    mati += 2 * board[x][y] - 1;
    board[x][y] = !board[x][y];
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> q; mati = n*m;
    ans = 0;
    for(int i=1; i<=n; i++){
        //cout << i << ",1: " << getKananBawah(i, 1, true) << ", " << getKananBawah(i, 1, false) << endl;
        ans += getKananBawah(i, 1, false) * (getKananBawah(i, 1, false) + 1) / 2;
    }
    for(int i=1; i<=m; i++){
        //cout << "1," << i << ": " << getKananBawah(1, i, true) << ", " << getKananBawah(1, i, false) << endl;
        ans += getKananBawah(1, i, true) * (getKananBawah(1, i, true) + 1) / 2;
    }
    //cout << ans - mati << endl;
    while(q--){
        cin >> u >> v;
        flip(u, v);
        cout << ans - mati << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 512;
bool b, sabi = true;
int n;
bitset<maxn> awal[maxn], akhir[maxn];

void print(){
    cout << "awal" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << awal[i][j];
        }cout << endl;
    }
    cout << "akhir" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << akhir[i][j];
        }cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        awal[i].reset();
        for(int j=0; j<n; j++){
            cin >> b;
            awal[i].set(j, b);
        }
        akhir[i].reset();
        akhir[i].set(i, true);
    }
    // print();
    // turun
    for(int i=0; i<n && sabi; i++){
        // pastikan awal[i] punya leading 1
        if(!awal[i][i]){
            int idx = -1;
            for(int j=i+1; j<n; j++){
                if(awal[j][i]){
                    idx = j;
                }
            }
            if(idx < 0){
                cout << -1 << endl;
                return 0;
            }else{
                awal[i] ^= awal[idx];
                akhir[i] ^= akhir[idx];
            }
        }
        for(int j=i+1; j<n; j++){
            if(awal[j][i]){
                awal[j] ^= awal[i];
                akhir[j] ^= akhir[i];
            }
        }
    }
    // print();
    // naik
    for(int i=n-1; i>=0; i--){
        for(int j=i-1; j>=0; j--){
            if(awal[j][i]){
                awal[j] ^= awal[i];
                akhir[j] ^= akhir[i];
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(akhir[i][j]){
                cout << j+1 << " ";
            }
        }cout << endl;
    }
}

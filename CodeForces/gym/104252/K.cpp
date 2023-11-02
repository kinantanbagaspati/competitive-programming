#include<bits/stdc++.h>
using namespace std;

int k, t;
vector<int> xs[16], ys[16];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> k;
    if(k == 1){
        cout << 0 << endl; return 0;
    }
    int pw2 = 2; t = 1;
    while(pw2 < k){
        pw2 *= 2; t++;
    }
    cout << t << endl;
    for(int i=0; i<k-1; i++){
        int row = i/99, col = i%99+1;
        row = row/2*3 + 2 + row%2;
        int cpy = i;
        for(int j=0; j<t; j++){
            if(cpy%2){
                xs[j].push_back(row);
                ys[j].push_back(col);
            } cpy /= 2;
        }
    }
    for(int i=0; i<t; i++){
        cout << xs[i].size() + 100*100 - 66*99;
        for(int j=0; j<xs[i].size(); j++){
            cout << " " << xs[i][j] << " " << ys[i][j];
        }
        for(int j=1; j<=100; j+=3){
            for(int k=1; k<100; k++){
                cout << " " << j << " " << k;
            }
        }
        for(int j=1; j<=100; j++){
            cout << " " << j << " " << 100; 
        }
        cout << endl;
    }
}
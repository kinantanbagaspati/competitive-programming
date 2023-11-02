#include<bits/stdc++.h>
using namespace std;

int q, k, c;

int main(){
    cin >> q >> k;
    while(q--){
        cin >> c;
        if((c | k) == c){
            cout << c << endl;
        }else{
            cout << -1 << endl;
        }
    }
}
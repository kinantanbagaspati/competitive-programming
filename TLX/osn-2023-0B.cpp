#include<bits/stdc++.h>
using namespace std;

int n, m, k;

int main(){
    cin >> n; m=0;
    while(n--){
        m++;
        cin >> k;
        if(m == k){
            cout << "BENAR" << endl; cout << flush;
        }else{
            cout << "SALAH" << endl; cout << flush;
            m=0;
        }
    }
}
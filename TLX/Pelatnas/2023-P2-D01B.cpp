#include <bits/stdc++.h>
using namespace std;

int n = 100;

int main(){
    cout << n;
    for(int i=n-1; i>0; i--){
        cout << endl << 1;
        for(int j=1; j<i; j++){
            cout << " 100";
        }
    }
}
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m;
    cin >> n;
    bool ada[n];
    for(int i=0; i<n; i++){
        ada[i] = false;
    }
    for(int i=0; i<n-1; i++){
        cin >> m;
        ada[m-1] = true;
    }
    for(int i=0; i<n; i++){
        if(!ada[i]){
            cout << i+1 << endl;
        }
    }
}

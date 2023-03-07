#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, q, a, b;
    cin >> n >> q;
    int x[n], prex[n+1];
    prex[0] = 0;
    for(int i=0; i<n; i++){
        cin >> x[i];
        prex[i+1] = prex[i]^x[i];
    }
    while(q--){
        cin >> a >> b;
        cout << (prex[b] ^ prex[a-1]) << endl;
    }
}

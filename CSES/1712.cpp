#include <bits/stdc++.h>
using namespace std;

long long pangkat(long long a, long long b, long long mod){
    long long res = 1;
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long q, a, b, c;
    long long mod = 1000000007;
    cin >> q;
    while(q--){
        cin >> a >> b >> c;
        cout << pangkat(a, pangkat(b, c, mod-1), mod) << endl;
    }
}

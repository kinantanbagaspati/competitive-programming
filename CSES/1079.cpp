#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

long long pangkat(long long a, long long b){
    a %= mod;
    b %= (mod-1);
    long long res = 1;
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}
long long inv(long long a){
    return pangkat(a, mod-2);
}
long long fac[1000069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    fac[0] = 1;
    for(int i=1; i<1000069; i++){
        fac[i] = (fac[i-1]*i)%mod;
    }
    long long n;
    cin >> n;
    long long a, b;
    while(n--){
        cin >> a >> b;
        cout << fac[a] * inv(fac[b]) % mod * inv(fac[a-b]) % mod << endl;

    }
}

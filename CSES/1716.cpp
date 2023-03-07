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

long long comb(long long a, long long b){
    long long ret = 1;
    while(b>0){
        ret *= (a*inv(b))%mod;
        ret %= mod;
        a--; b--;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    long long n, m;
    cin >> n >> m;
    cout << comb(n+m-1, n-1) << endl;
}

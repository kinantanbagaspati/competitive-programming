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

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, nbdiv = 1, nbdiv2 = 1, sumdiv = 1, muldiv = 1;
    cin >> n;
    long long a, b;
    while(n--){
        cin >> a >> b;
        nbdiv = nbdiv*(b+1)%mod;

        sumdiv *= (pangkat(a, b+1) - 1) * inv(a-1) % mod;
        sumdiv %= mod;

        muldiv = pangkat(muldiv, b+1);
        muldiv *= pangkat(a, b*(b+1)/2%(mod-1) * nbdiv2);
        muldiv %= mod;
        nbdiv2 = nbdiv2*(b+1)%(mod-1);
    }
    cout << nbdiv << " " << sumdiv << " " << muldiv << endl;
}

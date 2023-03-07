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
    long long n;
    cin >> n;
    if(n%2){
        cout << 0 << endl;
    }else{
        n/=2;
        long long ans = 1;
        for(int i=1; i<n; i++){
            ans = ans * inv(1+i)%mod;
            ans = ans * (n+1+i) % mod;
        }
        cout << ans << endl;
    }
}

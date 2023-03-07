#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;
long long pangkat(long long a, long long b){
    long long res = 1;
    b %= (mod-1);
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}
long long inv(long long a){
    return pangkat(a, mod-2);
}

long long ans[1000069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, ans=0;
    cin >> n;
    ans += (pangkat(2, n*n)-pangkat(2, (n*n+1)/2)+mod)*inv(4)%mod;
    ans += (pangkat(2, (n*n+1)/2)-pangkat(2, (n*n+3)/4)+mod)*inv(2)%mod;
    ans += pangkat(2, (n*n+3)/4);
    cout << ans%mod << endl;

}

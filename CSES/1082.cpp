#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, ans=0;
    cin >> n;
    long long m = floor(sqrt(n));
    for(long long i=1; n/i>m; i++){
        ans += n%i;
    }
    ans %= mod;
    for(long long i=1; i<=m; i++){
        long long cur = (n/i - n/(i+1))%mod;
        ans += cur*(cur-1)/2%mod *i%mod;
        ans += n%(n/i)%mod*cur%mod;
        ans %= mod;
    }
    cout << ((n%mod)*(n%mod) + mod - ans)%mod << endl;
}

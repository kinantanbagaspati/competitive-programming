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
    long long n, m;
    cin >> n >> m;
    for(int i=0; i<=n; i++){
        ans[i] = 0;
    }

    for(int i=n; i>0; i--){
        if(n%i==0){
            ans[i] = pangkat(m, n/i);
            for(int j=2; i*j<=n; j++){
                ans[i] -= ans[i*j] * n/(i*j);
            }
            ans[i] %= mod;
            if(ans[i]<0){ans[i] += mod;}
            ans[i] *= inv(n/i);
            ans[i] %= mod;
        }
    }
    long long ANS = 0;
    for(int i=1; i<=n; i++){
        ANS += ans[i];
    }
    cout << ANS%mod << endl;
}

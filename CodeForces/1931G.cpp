#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = (1<<23), mod = 998244353;
long long t, a, b, c, d;
long long fac[maxn], ifac[maxn];
long long pangkat(long long a, long long b){
    long long ret = 1;
    while(b>0){
        if(b%2){
            ret = ret*a%mod;
        }
        a = a*a%mod; b/= 2;
    }
    return ret;
}

void initFac(){
    fac[0] = 1;
    for(long long i=1; i<maxn; i++){
        fac[i] = fac[i-1]*i%mod;
    }
    ifac[maxn-1] = pangkat(fac[maxn-1], mod-2);
    for(long long i=maxn-1; i>0; i--){
        ifac[i-1] = ifac[i]*i%mod;
    }
    //cout << ifac[0] << endl;
}
long long choose(long long a, long long b){
    if(b < 0 || a < b){
        return 0;
    }else{
        return ifac[b] * ifac[a-b] % mod * fac[a] % mod;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    initFac();
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        if(a+b==0){
            cout << (min(c,d)==0) << endl;
        }else if(abs(a-b)==1){
            cout << choose(c + min(a,b), min(a,b)) * choose(d + min(a,b), min(a,b)) % mod << endl; 
        }else if(a == b){
            cout << (choose(c+a-1,a-1)*choose(d+b,b)%mod + choose(c+a,a)*choose(d+b-1,b-1)%mod)%mod << endl;
        }else{
            cout << 0 << endl;
        }
    }
}
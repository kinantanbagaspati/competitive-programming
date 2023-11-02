#include<bits/stdc++.h>
using namespace std;
#define pdd pair<double, double>

const long long mod = 998244353;
long long n, q, m, ans=1;
char c;
string s;
long long pangkat(long long a, long long b){
    a %= mod; b %= mod-1;
    long long res = 1;
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}
long long inverse(long long a){
    return pangkat(a, mod-2);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q >> s;
    for(int i=1; i<n-1; i++){
        if(s[i] == '?'){
            ans = ans * i % mod;
        }
    }
    if(s[0] == '?'){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }
    while(q--){
        cin >> m >> c; m--;
        if(m){
            if(s[m] == '?'){
                ans = ans * inverse(m) % mod;
            }
            if(c == '?'){
                ans = ans * m % mod;
            }
        }
        s[m] = c;
        if(s[0] == '?'){
            cout << 0 << endl;
        }else{
            cout << ans << endl;
        }
    }
}
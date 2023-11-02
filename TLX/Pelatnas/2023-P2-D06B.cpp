#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
long long n, ans = 0, kiri = 0, kanan = 0, mul = 1;
string s;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> s;
    for(int i=0; i<n; i++){
        kiri = kiri * 31 + (s[i]-'A'); kiri %= mod;
        kanan = mul * (s[n-1-i]-'A') + kanan; kanan %= mod;
        mul = mul * 31 % mod;
        if(kiri == kanan){
            ans++; mul = 1;
            kiri = 0; kanan = 0;
        }
    }
    cout << ans << endl;
}
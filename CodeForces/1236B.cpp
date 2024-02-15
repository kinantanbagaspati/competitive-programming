#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long mod = 1e9+7;
long long n, m;

long long pangkat(long long a, long long b){
    a %= mod; b %= mod-1;
    long long res = 1;
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    cout << pangkat(pangkat(2, m) + mod - 1, n) << endl;
}

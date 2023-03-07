#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long pangkat(long long a, long long b){
    long long res = 1;
    while(b>0){
        if(b%2 == 1){
            res = (res * a)% mod;
        }
        b /= 2;
        a = (a*a) % mod;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    cout << pangkat(2, n) << endl;
}

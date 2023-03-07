#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    long long x = 1;
    long long y = 0;
    long long z;
    for(int i=2; i<=n; i++){
        z = y;
        y = (i-1) * (x+y) % mod;
        x = z;
    }
    if(n==1){
        cout << 0 << endl;
    }else{
        cout << y << endl;
    }
}

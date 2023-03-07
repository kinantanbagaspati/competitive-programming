#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    if(n>0){cout << 0 << endl;}
    if(n>1){cout << 6 << endl;}
    if(n>2){cout << 28 << endl;}
    if(n>3){cout << 96 << endl;}
    for(long long i=5; i<=n; i++){
        long long ans = i*i*(i*i-1);
        ans -= 4*2;
        ans -= 8*3;
        ans -= 4*4;
        ans -= 4*(i-4)*4;
        ans -= 4*(i-4)*6;
        ans -= (i-4)*(i-4)*8;
        ans /= 2;
        cout << ans << endl;
    }
}

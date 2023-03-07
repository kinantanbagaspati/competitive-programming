#include <bits/stdc++.h>
using namespace std;

long long ans[1000069], diag[1000069], tri[1000069];
long long mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ans[0] = 1;
    diag[0] = 1;
    tri[0] = 1;
    for(int i=1; i<1000069; i++){
        ans[i] = 2*tri[i-1]%mod;
        diag[i] = (diag[i-1]+ans[i])%mod;
        tri[i] = (3*tri[i-1] + ans[i] + mod - diag[i-1])%mod;
    }
    long long t, n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << ans[n] << endl;
    }
}

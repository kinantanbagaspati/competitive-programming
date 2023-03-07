#include <bits/stdc++.h>
using namespace std;

long long mod = 1000000007;
long long ans[1000069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ans[0] = 1;
    long long n;
    cin >> n;
    for(int i=1; i<=n; i++){
        ans[i] = 0;
        for(int j=1; j<=6 && i-j>=0; j++){
            ans[i] += ans[i-j];
            ans[i] %= mod;
        }
    }
    cout << ans[n] << endl;
}

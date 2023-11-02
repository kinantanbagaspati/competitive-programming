#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>
 
const long long mod = 998244353;
long long ans = 0, cur = 1, n;
 
int main(){
    cin >> n;
    for(int i=n; i>1; i--){
        cur = cur * i % mod;
        ans = (ans + mod - cur) % mod;
    }
    ans = (ans + n*cur) % mod;
    cout << ans << endl;
}
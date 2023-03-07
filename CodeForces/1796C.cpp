#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long mod = 998244353;
long long t, a, b, ans, tot;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b;
        if(b < a*2){
            cout << 1 << " " << b-a+1 << endl;
        }else{
            ans = 0; tot = 0;
            for(int i=a*2; i<=b; i*=2){
                ans++;
            }
            tot += max(b/(1<<ans) - a + 1, 0LL); tot %= mod;
            tot += ans * max(b/((1<<ans)*3/2) - a + 1, 0LL); tot %= mod;
            cout << ans+1 << " " << tot << endl;
        }
    }
}

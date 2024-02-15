#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, a[262144], mn, mx, ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i+1]; a[i+1] += a[i];
        }
        ans = 0;
        for(int i=1; i<=n; i++){
            if(n%i == 0){
                mn = 1e18; mx = -1e18;
                for(int j=0; j<n; j+=n/i){
                    mn = min(mn, a[j+n/i]-a[j]);
                    mx = max(mx, a[j+n/i]-a[j]);
                }
                ans = max(ans, mx-mn);
            }
        }
        cout << ans << endl;
    }
}

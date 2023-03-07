#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;

long long n, d, a, mn[2], mx[2], ans;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> d;
    mn[0] = 1e18; mn[1] = 1e18;
    mx[0] = -1e18; mx[1] = -1e18;
    for(int i=0; i<n; i++){
        cin >> a;
        mn[0] = min(mn[0], a-i*d);
        mn[1] = min(mn[1], a+i*d);
        mx[0] = max(mx[0], a-i*d);
        mx[1] = max(mx[1], a+i*d);
    }
    ans = min(mx[0]-mn[0], mx[1]-mn[1]);
    cout << ans/2 << '.' << ans%2*5 << endl;
}

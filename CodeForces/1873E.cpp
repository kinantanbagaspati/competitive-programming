#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, x, ans, a[262144];
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> x;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a, a+n);
        ans = a[0];
        for(int i=1; i<n && x>0; i++){
            ans += min(a[i]-a[i-1], x/i);
            x = max(x - (a[i]-a[i-1]) * i, 0LL);
        }
        cout << ans + x/n << endl;
    }
}
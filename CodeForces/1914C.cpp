#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, n, k, a[262144], b[262144], ans, cur, tambah;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
        }
        ans = 0; cur = 0, tambah = 0;
        for(int i=0; i<n && i<k; i++){
            cur += a[i];
            tambah = max(tambah, b[i]);
            ans = max(cur + tambah*(k-i-1), ans);
        }
        cout << ans << endl;
    }
}
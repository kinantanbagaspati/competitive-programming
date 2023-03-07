#include <bits/stdc++.h>
using namespace std;

long long a[200069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, d, ans = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i] >> d;
        ans += d;
    }
    sort(a, a+n);
    for(int i=0; i<n; i++){
        ans -= (n-i)*a[i];
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    long long p[n];
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    sort(p, p+n);
    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += abs(p[i] - p[n/2]);
    }
    cout << ans << endl;
}

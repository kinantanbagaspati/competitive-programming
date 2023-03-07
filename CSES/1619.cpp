#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, l, r;
    cin >> n;
    pair<long long, long long> p[2*n];
    long long ans = 0, cur = 0;
    for(int i=0; i<n; i++){
        cin >> l >> r;
        p[2*i] = {l,-1};
        p[2*i+1] = {r,1};
    }
    sort(p, p+2*n);
    for(int i=0; i<2*n; i++){
        cur -= p[i].second;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}

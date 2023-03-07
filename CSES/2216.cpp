#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    long long x[n], pos[n+1];
    for(int i=0; i<n; i++){
        cin >> x[i];
        pos[x[i]] = i;
    }
    long long ans = 1;
    for(int i=1; i<n; i++){
        ans += pos[i]>pos[i+1];
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, x;
    cin >> n >> x;
    long long p[n];
    for(int i=0; i<n; i++){
        cin >> p[i];
    }
    sort(p, p+n);
    long long ans=0, idx=0;
    for(int i=n-1; i>=idx; i--){
        if(p[i]+p[idx]<=x){
            idx++;
        }
        ans++;
    }
    cout << ans << endl;
}

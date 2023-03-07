#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m, k;
    cin >> n >> m >> k;
    long long a[n], b[m];
    for(int i=0; i<n; i++){cin >> a[i];}
    for(int i=0; i<m; i++){cin >> b[i];}
    sort(a, a+n);
    sort(b, b+m);
    long long ans = 0, idx = 0;
    for(int i=0; i<n; i++){
        while(idx<m && b[idx]<a[i]-k){
            idx++;
        }
        if(idx<m && b[idx]<=a[i]+k){
            idx++;
            ans++;
        }
    }
    cout << ans << endl;
}

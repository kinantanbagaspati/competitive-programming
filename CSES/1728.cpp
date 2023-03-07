#include <bits/stdc++.h>
using namespace std;

long long n, r[101];
double ans = 0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> r[i];
        for(int j=0; j<i; j++){
            long long ad = 0;
            for(long long k=0; k<r[j]; k++){
                ad += min(k, r[i]);
            }
            ans += (double) ad / (r[i]*r[j]);
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}

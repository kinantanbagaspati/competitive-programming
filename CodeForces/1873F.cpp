#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, k, a[262144], h[262144];
long long kiri, ans, sum;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k; kiri = 0; ans = 0; sum = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> h[i];
            sum += a[i];
            while(sum > k){
                sum -= a[kiri]; kiri++;
            }
            while(kiri < i && h[i-1] % h[i] != 0){
                sum -= a[kiri]; kiri++;
            }
            ans = max(i - kiri + 1, ans);
        }
        cout << ans << endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144, mod = 998244353;
long long t, n, k, x, minsum, maxsum, minans, maxans;
long long a[maxn], b[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k >> x;
        b[0] = 0;
        for(int i=0; i<n; i++){
            cin >> a[i]; a[i] -= x;
            b[i+1] = a[i]+b[i];
        }x *= 2;
        minsum = 0; maxsum = 0;
        minans = 0; maxans = 0;
        for(int i=0; i<n; i++){
            for(int j=1; j<k; j++){
                if(i+1 >= j){
                    maxans = max(maxans, b[i+1] - b[i+1-j] + j*x);
                    minans = min(minans, b[i+1] - b[i+1-j] + j*x);
                }
            }
            if(i+1 >= k){
                minsum = min(b[i+1-k], minsum);
                maxsum = max(b[i-1+k], maxsum);
                minans = min(minans, b[i+1] - maxsum + k*x);
                maxans = max(maxans, b[i+1] - minsum + k*x);
            }
        }
        cout << minsum << " " << maxsum << endl;
        cout << minans << " " << maxans << endl;
        cout << b[n] << " " << k << x << endl;
        cout << max(maxans, b[n]+k*x-minans) << endl;
    }
}

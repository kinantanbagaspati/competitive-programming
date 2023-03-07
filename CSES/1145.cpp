#include <bits/stdc++.h>
using namespace std;

long long n, x[200069];
long long dp[200069], sz = 1;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x[i];
        long long lo = 0, hi = sz, mid;
        while(hi-lo > 1){
            mid = (lo+hi)/2;
            if(dp[mid] < x[i]){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        dp[hi] = x[i];
        if(hi == sz){
            sz++;
        }
    }
    /*
    for(int i=0; i<=sz; i++){
        cout << dp[i] << " ";
    }
    */
    cout << sz-1 << endl;
}

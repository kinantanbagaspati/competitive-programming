#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069;
long long n, k, x[maxn];
long long lo, hi, mid, nbsa, cursum;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    lo = 0;
    for(int i=0; i<n; i++){
        cin >> x[i];
        lo = max(x[i]-1, lo);
    }
    hi = 1e18;
    while(hi-lo>1){
        mid = (lo+hi+1)/2;
        //cout << lo << " " << mid << " " << hi << endl;
        nbsa = 1; cursum = 0;
        for(int i=0; i<n; i++){
            if(cursum + x[i] > mid){
                nbsa++;
                cursum = x[i];
            }else{
                cursum += x[i];
            }
        }
        if(nbsa > k){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    cout << hi << endl;
}

#include<bits/stdc++.h>
using namespace std;

const long long maxn = 524288;
long long n, k, v[maxn], lo, mid, hi;
long long sabi[maxn], kiri, sum;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v, v+n);

    lo = 0; hi = v[n-1]-v[0]+1;
    sabi[0] = 1;
    while(hi-lo > 1){
        mid = (lo+hi)/2;
        kiri = 0; sum = 0;
        //cout << "lomidhi " << lo << " " << mid << " " << hi << endl;
        for(int i=k; i<=n; i++){
            while(kiri<n && v[i-1]-v[kiri] >= mid){
                sum -= sabi[kiri]; kiri++;
            }
            sum += sabi[i-k];
            //cout << i << " " << kiri << "-" << i-k << ": " << sum << endl;
            sabi[i] = (sum > 0);
        }
        if(sabi[n]){
            hi = mid;
        }else{
            lo = mid;
        }
    }
    cout << lo << endl;
}
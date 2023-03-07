#include <bits/stdc++.h>
using namespace std;

long long n, t, k[200069];
long long lo, mid, hi, cur;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> t;
    for(int i=0; i<n; i++){
        cin >> k[i];
    }
    lo = 0; hi = 1e18;
    while(hi-lo>1){
        mid = (lo+hi)/2;
        cur = 0;
        bool exceed = false;
        for(int i=0; i<n; i++){
            cur += mid/k[i];
            if(cur >= t){exceed = true;}
        }
        if(!exceed){lo = mid;}
        else{hi = mid;}
    }
    cout << hi << endl;
}

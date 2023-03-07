#include <bits/stdc++.h>
using namespace std;

long long last[200069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, x;
    cin >> n;
    last[0] = 0;
    for(int i=1; i<=n+1; i++){
        last[i] = 1e18;
    }
    for(int i=0; i<n; i++){
        cin >> x;
        long long l = 0, r = n+1, m = (l+r)/2;
        while(l<m){
            if(last[m] <= x){l = m;}
            else{r = m;}
            m = (l+r)/2;
        }
        last[r] = x;
    }
    int ans = n+1;
    while(last[ans]==1e18){ans--;}
    cout << ans << endl;
}

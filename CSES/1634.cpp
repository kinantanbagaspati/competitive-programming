#include <bits/stdc++.h>
using namespace std;

long long ans[1000069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, x;
    cin >> n >> x;
    long long c[n];
    for(int i=0; i<n; i++){cin >> c[i];}
    ans[0] = 0;
    for(int i=1; i<=x; i++){
        ans[i] = 1e18;
        for(int j=0; j<n; j++){
            if(i>=c[j]){
                ans[i] = min(ans[i], ans[i-c[j]]+1);
            }
        }
    }
    if(ans[x] == 1e18){
        cout << -1 << endl;
    }else{
        cout << ans[x] << endl;
    }
}

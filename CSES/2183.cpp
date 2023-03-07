#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    long long x[n];
    for(int i=0; i<n; i++){
        cin >> x[i];
    }
    sort(x, x+n);
    long long ans = 1;
    bool found = false;
    for(int i=0; i<n && !found; i++){
        if(x[i]>ans){
            found = true;
        }else{
            ans += x[i];
        }
    }
    cout << ans << endl;
}

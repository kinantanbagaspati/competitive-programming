#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, x, ans=0, cur=0, mx=-1e18;
    cin >> n;
    while(n--){
        cin >> x;
        cur += x;
        cur = max(cur, 0ll);
        ans = max(ans, cur);
        mx = max(mx, x);
    }
    if(mx<0){
        cout << mx << endl;
    }else{
        cout << ans << endl;
    }
}

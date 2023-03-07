#include <bits/stdc++.h>
using namespace std;

long long x[200069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, ans=0, cur;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x[i];
        if(i>0){
            ans += max(0ll, cur-x[i]);
            cur = max(cur, x[i]);
        }else{
            cur = x[i];
        }
    }
    cout << ans << endl;
}

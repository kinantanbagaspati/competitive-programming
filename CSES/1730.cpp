#include <bits/stdc++.h>
using namespace std;

long long t, n, x, ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        while(n--){
            cin >> x;
            ans ^= x;
        }
        if(ans){
            cout << "first" << endl;
        }else{
            cout << "second" << endl;
        }
    }
}

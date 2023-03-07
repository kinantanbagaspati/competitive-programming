#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string ans;
    long long t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        ans = "NO";
        if((a+b)%3 == 0){
            if(2*a>=b && 2*b >=a){
                ans = "YES";
            }
        }
        cout << ans << endl;
    }
}

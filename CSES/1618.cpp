#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, ans = 0;
    cin >> n;
    while(n>0){
        n /= 5;
        ans += n;
    }
    cout << ans << endl;
}

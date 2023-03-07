#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, a1, b1, a2, b2, a0, b0;
    cin >> n;
    cin >> a0 >> b0;
    a1 = a0; b1 = b0;
    n--;
    long long ans = 0;
    while(n--){
        cin >> a2 >> b2;
        ans += a1*b2 - a2*b1;
        a1 = a2; b1 = b2;
    }
    ans += a1*b0 - a0*b1;
    cout << abs(ans) << endl;
}

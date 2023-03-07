#include <bits/stdc++.h>
using namespace std;

long long n, t, mx = 0, sum = 0;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> t;
        mx = max(mx, t);
        sum += t;
    }
    cout << max(2*mx, sum) << endl;
}

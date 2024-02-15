#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, x, y, k;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> x >> y >> k;
        cout << min(abs(y) + abs(y-x), abs(x) + abs(y-x) + max(abs(y-x)-k, 0)) << endl;
    }
}

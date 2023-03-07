#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, a, b, ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> a; n--; ans = 0;
        while(n--){
            cin >> b;
            if((a-b)%2 == 0){
                ans++;
            }
            a = b;
        }
        cout << ans << endl;
    }
}

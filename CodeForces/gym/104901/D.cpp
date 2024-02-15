#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, la, ra, lb, rb;

int getDigit(int x){
    int ret = 0;
    while(x > 0){
        ret = max(x%10, ret); x /= 10;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> la >> ra >> lb >> rb;
        if(ra+rb -la-lb > 10){
            cout << 9 << endl;
        }else{
            int ans = 0;
            for(int i=la+lb; i<=ra+rb; i++){
                ans = max(getDigit(i), ans);
            }
            cout << ans << endl;
        }
    }
}

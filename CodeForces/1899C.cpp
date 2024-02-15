#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, ans, sum, a, prv;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> a; ans = a; prv = a;
        if(a >= 0){
            sum = a;
        }else{
            sum = 0;
        }
        for(int i=1; i<n; i++){
            cin >> a;
            ans = max(ans, a);
            if(sum + a < 0){
                sum = 0;
            }else if((prv+a)%2 == 0){
                if(a >= 0){
                    sum = a;
                }else{
                    sum = 0;
                }
            }else{
                sum += a;
                ans = max(sum, ans);
            }
            prv = a;
        }
        cout << ans << endl;
    }
}

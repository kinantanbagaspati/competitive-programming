#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, a, ans;
multiset<long long> ms;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n; ans = 0;
        ms.clear();
        while(n--){
            cin >> a;
            if(a){
                ms.insert(-a);
            }else if(!(ms.empty())){
                ans -= *(ms.begin());
                ms.erase(ms.begin());
            }
            //cout << ans << ", ";
        }
        cout << ans << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    long long p[n], tot=0;
    for(int i=0; i<n; i++){cin >> p[i]; tot+=p[i];}
    long long ans = 1e18;
    for(int i=0; i<(1<<n); i++){
        long long cpy=i;
        long long cur=0;
        long long idx=0;
        while(cpy>0){
            if(cpy%2){
                cur += p[idx];
            }
            idx++;
            cpy/=2;
        }
        ans = min(abs(2*cur - tot), ans);
    }
    cout << ans << endl;
}

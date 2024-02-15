#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, a[262144], b[262144], ans;
pll swings[262144];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
            swings[i] = {2 - a[i] - b[i], 1 - a[i]};
        }
        sort(swings, swings + n);
        ans = 0;
        for(int i=0; i<n; i++){
            if(i%2){
                ans += swings[i].first - swings[i].second;
            }else{
                ans -= swings[i].second;
            }
        }
        cout << ans << endl;
    }
}
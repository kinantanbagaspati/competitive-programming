#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, ans[65536];
pll ai[65536];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> ai[i].first; ai[i].second = i;
        }
        sort(ai, ai+n);
        for(int i=0; i<n; i++){
            ans[ai[i].second] = n-i;
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }cout << endl;
    }
}
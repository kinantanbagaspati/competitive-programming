#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, a, ans;
map<long long, long long> m;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n; m.clear();
        ans = 0;
        for(int i=0; i<n; i++){
            cin >> a; ans += m[a]; m[a]++;
        }
        cout << ans + m[1]*m[2] << endl;
    }
}

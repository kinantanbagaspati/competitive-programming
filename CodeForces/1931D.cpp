#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
long long t, n, x, y, a;
map<long long, map<long long, long long>> m;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        m.clear();
        long long ans = 0;
        for(int i=0; i<n; i++){
            cin >> a;
            ans += m[a%y][(x-a%x)%x];
            m[a%y][a%x]++;
        }
        cout << ans << endl;
    }
}
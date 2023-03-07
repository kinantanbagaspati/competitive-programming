#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;
long long t, n, pos[maxn], a, b, idx, ans;
bool used[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a; pos[a] = i;
        }
        idx = 0; ans = 0;
        for(int i=0; i<n; i++){
            while(used[idx]){
                idx++;
            }
            cin >> b;
            ans += (pos[b] != idx);
            used[pos[b]] = true;
        }
        cout << ans << endl;
        for(int i=0; i<n; i++){
            used[i] = false;
        }
    }
}

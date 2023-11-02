#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, k, ans;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k >> s; ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'B'){
                i += k-1; ans++;
            }
        }
        cout << ans << endl;
    }
}
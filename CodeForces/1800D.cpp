#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, ans;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> s; ans = n-1;
        for(int i=2; i<n; i++){
            ans -= (s[i-2] == s[i]);
        }
        cout << ans <<endl;
    }
}

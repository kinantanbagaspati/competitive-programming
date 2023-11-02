#include<bits/stdc++.h>
using namespace std;

int t, ans;
string s0 = "codeforces", s1;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s1; ans = 0;
        for(int i=0; i<10; i++){
            ans += (s0[i] != s1[i]);
        }
        cout << ans << endl;
    }
}
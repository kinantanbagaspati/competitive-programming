#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, n;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n; n-= 3;
        s = "aaa";
        s[2] += min(25, n); n = max(0, n-25);
        s[1] += min(25, n); n = max(0, n-25);
        s[0] += min(25, n); n = max(0, n-25);
        cout << s << endl;
    }
}
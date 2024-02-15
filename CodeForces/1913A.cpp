#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, idx;
string s, a, b;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        idx = 1;
        a = " "; a[0] = s[0];
        while(idx < s.length() && s[idx] == '0'){
            a += " "; a[idx] = s[idx];
            idx++;
        }
        b = "";
        while(idx < s.length()){
            b += " "; b[b.length()-1] = s[idx];
            idx++;
        }
        if((a.length() > b.length()) || (a.length() == b.length() && a >= b)){
            cout << -1 << endl;
        }else{
            cout << a << ' ' << b << endl;
        }
    } 
}
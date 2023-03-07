#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    long long ans = 0;
    long long cur = 1;
    for(int i=1; i<s.length(); i++){
        if(s[i] == s[i-1]){
            cur++;
        }else{
            ans = max(ans, cur);
            cur = 1;
        }
    }
    cout << max(ans, cur) << endl;
}

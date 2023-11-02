#include<bits/stdc++.h>
using namespace std;

int t, n, m, ans;
string x, s;

bool isSub(){
    for(int i=0; i<=x.length() - s.length(); i++){
        bool same = true;
        for(int j=0; j<s.length(); j++){
            same = same && (x[i+j] == s[j]);
        }
        if(same){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        cin >> x >> s;
        ans = 0;
        while(x.length() < s.length()){
            x += x; ans++;
        }
        if(isSub()){
            cout << ans << endl;
        }else{
            x += x; ans++;
            if(isSub()){
                cout << ans << endl;
            }else{
                cout << -1 << endl;
            }
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long mod = 998244353;
long long t, n;
string text = "FBFFBFFBFBFFBFFBFBFFBFFB", s;
bool nemu, cur;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> s;
        nemu = false;
        for(int i=0; i<8; i++){
            cur = true;
            for(int j=0; j<s.length(); j++){
                cur = cur && (text[i+j] == s[j]);
            }
            nemu = nemu || cur;
        }
        if(nemu){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}

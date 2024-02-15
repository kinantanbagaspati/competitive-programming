#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxn = 1048576;
int t, sz;
string s;
char st[maxn];
bool tipe[2];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        bool ans = false; tipe[0] = false; tipe[1] = false;
        sz = 0;
        for(int i=0; i<s.length() && !ans; i++){
            if(s[i] == ')'){
                s[i] = '(';
            }else if(s[i] == ']'){
                s[i] = '[';
            }
            if(sz == 0 || st[sz-1] != s[i]){ // naik
                st[sz] = s[i];
                ans = ans || (i>0 && s[i] == s[i-1]); 
                if(sz == 0){
                    //cout << i << endl; 
                    ans = ans || tipe[(s[i] == '(')];
                    tipe[(s[i] == '(')] = true;
                } 
                sz++;
            }else{
                sz--;
            }
        }
        if(ans){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
}

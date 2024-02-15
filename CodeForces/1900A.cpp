#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, cur, ans;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> s; cur = 0; ans = 0;
        for(int i=0; i<n && cur < 3; i++){
            if(s[i] == '.'){
                cur++;
                if(cur == 3){
                    ans = 2;
                }
            }else{
                ans += cur; cur = 0;
            }
        }
        if(cur == 3){
            cout << ans << endl;
        }else{
            cout << ans + cur << endl;
        }
    } 
}
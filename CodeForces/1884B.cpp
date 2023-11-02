#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, ans, idx0;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> s; 
        ans = 0; idx0 = n;
        for(int i=n-1; i>=0; i--){
            idx0 = min((long long)i, idx0);
            while(idx0 >= 0 && s[idx0] == '1'){
                idx0--;
            }
            //cout << endl << "idx0 " << idx0 << endl;
            if(idx0<0){
                cout << "-1 ";
            }else if(s[i] == '1'){
                ans += i - idx0;
                s[idx0] = '1'; s[i] = '0';
                cout << ans << ' ';
            }else{
                cout << ans << ' ';
            }
        }cout << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

int t, n, cur[4], idx, dur;
char c;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cur[1] = 1e9;
        cur[2] = 1e9;
        cur[3] = 1e9;
        while(n--){
            cin >> dur; idx = 0;
            cin >> c; idx += 2*(c=='1');
            cin >> c; idx += (c=='1');
            cur[idx] = min(cur[idx], dur);
        }
        if(cur[1] + cur[2] >= 1e9){
            if(cur[3] >= 1e9){
                cout << -1 << endl;
            }else{
                cout << cur[3] << endl;
            }
        }else{
            if(cur[3] >= 1e9){
                cout << cur[1] + cur[2] << endl;
            }else{
                cout << min(cur[3], cur[1] + cur[2]) << endl;
            }
        }
    }
}
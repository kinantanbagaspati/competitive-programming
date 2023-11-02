#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, ans;
char c;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        ans = 0;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                cin >> c;
                ans += min(min(1+i, 10-i), min(1+j, 10-j)) * (c == 'X');
            }
        }
        cout << ans << endl;
    }
}
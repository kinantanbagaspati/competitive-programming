#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, n, freq[32], ans;
char c;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        for(int i=0; i<32; i++){
            freq[i] = 0;
        }
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> c;
            freq[c-'A']++;
        }
        ans = 0;
        for(int i=0; i<32; i++){
            ans += (freq[i] > i);
        }
        cout << ans << endl;
    }
}
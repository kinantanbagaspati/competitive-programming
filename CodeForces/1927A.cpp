#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, n, lo, hi;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> s;
        for(int i=0; i<n; i++){
            if(s[i] == 'B'){
                hi = i;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'B'){
                lo = i;
            }
        }
        cout << hi-lo+1 << endl;
    }
}
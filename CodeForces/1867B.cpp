#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, beda;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> s; beda = 0;
        for(int i=0; i<n/2; i++){
            beda += (s[i] != s[s.length()-1-i]);
        }
        for(int i=0; i<beda; i++){
            cout << 0;
        }
        for(int i=beda; i<=n-beda; i++){
            if(n%2){
                cout << 1;
            }else{
                cout << (i-beda+1)%2;
            }
        }
        for(int i=0; i<beda; i++){
            cout << 0;
        }
        cout << endl;
    }
}
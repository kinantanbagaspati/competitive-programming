#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, n, a[262144], b[262144];
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        s = "";
        for(int i=0; i<n; i++){
            cin >> a[i]; 
            s += "a";
            s[i] += b[a[i]];
            b[a[i]]++;
        }
        cout << s << endl;
        for(int i=0; i<n; i++){
            b[i] = 0;
        }
    }
}
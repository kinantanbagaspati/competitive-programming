#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        if(s == "bca" || s == "cab"){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}
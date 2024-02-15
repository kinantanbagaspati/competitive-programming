#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, a, b, c;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> c; a %= 2; b %= 2; c %= 2;
        if(a == b){
            if(a == c){
                cout << "1 1 1" << endl;
            }else{
                cout << "0 0 1" << endl;
            }
        }else if(b == c){
            cout << "1 0 0" << endl;
        }else{
            cout << "0 1 0" << endl;
        }
    } 
}
#include<bits/stdc++.h>
using namespace std;

long long t, a, b, c, m, n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        m = min(min(a, b), c);
        if(a%m == 0 && b%m == 0 && c%m == 0 && (a+b+c)/m <= 6){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
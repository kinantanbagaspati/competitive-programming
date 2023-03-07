#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long t;
    long long a1, a2, a3, b1, b2, b3;
    cin >> t;
    while(t--){
        cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
        a2 -= a1; a3 -= a1;
        b2 -= b1; b3 -= b1;
        long long res = a2*b3 - a3*b2;
        if(res<0){
            cout << "RIGHT" << endl;
        }else if(res > 0){
            cout << "LEFT" << endl;
        }else{
            cout << "TOUCH" << endl;
        }
    }
}

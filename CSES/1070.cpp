#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long x, y, t;
    cin >> t;
    while(t--){
        cin >> x >> y;
        if(x<y){
            if(y%2 == 0){
                cout << (y-1)*(y-1) + x << endl;
            }else{
                cout << y*y+1-x << endl;
            }
        }else{
            if(x%2 == 0){
                cout << x*x+1-y << endl;
            }else{
                cout << (x-1)*(x-1)+y << endl;
            }
        }
    }
}

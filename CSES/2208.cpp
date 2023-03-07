#include <bits/stdc++.h>
using namespace std;

long long t, n, x;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        bool alleven = true;
        while(n--){
            cin >> x;
            if(x%2){
                alleven = false;
            }
        }
        if(alleven){
            cout << "second" << endl;
        }else{
            cout << "first" << endl;
        }
    }
}

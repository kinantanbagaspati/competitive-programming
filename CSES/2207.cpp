#include <bits/stdc++.h>
using namespace std;

long long t, n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n<3){
            cout << "second" << endl;
        }else if(n%3 == 1){
            cout << "second" << endl;
        }else{
            cout << "first" << endl;
        }
    }
}

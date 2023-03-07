#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, x, y;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> x >> y;
        cout << 2*(x-y) << endl;
        for(int i=x; i>y; i--){
            cout << i << " ";
        }
        for(int i=y; i<x; i++){
            cout << i << " ";
        }
        cout << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, q, d, cur;
bool sabi;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        for(int i=1; i<n; i++){
            cout << i << ' ' << i+1 << endl;
        }
        cur = n-1;
        while(q--){
            cin >> d;
            if(d == cur){
                cout << "-1 -1 -1" << endl;
            }else{
                cout << n << ' ' << cur << ' ' << d << endl;
                cur = d;
            }
        }
    }
}

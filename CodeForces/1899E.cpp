#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, idx, a[262144];
bool sabi;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> a[0]; 
        idx = 0; sabi = true;
        for(int i=1; i<n; i++){
            cin >> a[i];
            if(a[idx] > a[i]){
                idx = i; sabi = true;
            }else if(a[i] < a[i-1]){
                sabi = false;
            }
        }
        if(sabi){
            cout << idx << endl;
        }else{
            cout << -1 << endl;
        }
    }
}

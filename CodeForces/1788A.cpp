#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, a[1024], b, c;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n; b = 0;
        for(int i=0; i<n; i++){
            cin >> a[i];
            a[i]--; b += a[i];
        }
        if(b%2){
            cout << -1 << endl;
        }else if(b==0){
            cout << 1 << endl;
        }else{
            c = 0;
            for(int i=0; c<b/2; i++){
                c += a[i];
                if(c == b/2){
                    cout << i+1 << endl;
                }
            }
        }
    }
}

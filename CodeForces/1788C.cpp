#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, m, k, dif;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n%2){
            cout << "Yes" << endl;
            m = n*2+1+n/2;
            dif = 2*n - (m-2*n);
            for(k=1; k*2+dif <= m; k++){
                cout << k << " " << k+dif << endl;;
            }
            for(int i=k; i<(k+1+dif)/2; i++){
                cout << i << " " << (dif+1-k)/2 + i << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }
}
/*9 10 11 12 13
1 2 3 4 5 6 7 8 9 10*/

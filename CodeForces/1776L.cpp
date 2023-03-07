#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long n, dif, q, a, b, c;
char ch;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    dif = -n;
    for(int i=0; i<n; i++){
        cin >> ch;
        dif += 2*(ch == '+');
    }
    dif = abs(dif);
    cin >> q;
    while(q--){
        cin >> a >> b; c = __gcd(a, b);
        if(a == b){
            if(dif == 0){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else if(dif % (a/c - b/c) == 0){
            long long dv = abs(dif/(a/c-b/c));
            //cout << "HALO " << dv << endl;
            //cout << dif << " " << (a/c-b/c) << endl;
            //cout << (n-dif)/2 << " " << min(a,b)/c << endl;
            //cout << (n+dif)/2 << " " << max(a,b)/c << endl;
            if((n-dif)/2 >= min(a, b)/c * dv){
                if((n+dif)/2 >= max(a, b)/c * dv){
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }
            }else{
                cout << "NO" << endl;
            }
        }else{
            cout << "NO" << endl;
        }
    }
}

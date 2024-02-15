#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
long long t, n, a[maxn], avg, sum;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n; avg = 0; sum = 0;
        for(int i=0; i<n; i++){
            cin >> a[i]; avg += a[i];
        }
        avg /= n;
        bool bisa = true;
        for(int i=0; i<n; i++){
            sum += a[i]-avg;
            bisa = bisa && (sum >= 0);
        }
        if(bisa){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, y, sumn, sumy, temp;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n; temp = n;
        sumn = 0; sumy = 0;
        while(temp > 0){
            sumn += temp % 10;
            temp /= 10;
        }
        temp = 1; sumy = sumn/2; y = 0;
        while(sumy > 0){
            y += temp * min(sumy, n/temp%10);
            sumy -= min(sumy, n/temp%10);
            temp = temp*10;
        }
        cout << n-y << ' ' << y << endl;
    }
}

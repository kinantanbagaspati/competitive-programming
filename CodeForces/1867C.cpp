#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, ans, masuk;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ans = 0;
        while(n--){
            cin >> masuk;
            if(ans == masuk){
                ans++;
            }
        }
        masuk = ans;
        while(masuk >= 0){
            cout << masuk << endl; cout << flush;
            cin >> masuk; 
        }
    }
}
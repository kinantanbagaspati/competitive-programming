#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, n, a, prv, lo, hi, cur;
int grup[262144], awal[262144];
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n; prv = -1; cur = -1;
        for(int i=0; i<n; i++){
            cin >> a;
            if(a != prv){
                cur++; awal[cur] = i;
            }
            prv = a;
            grup[i] = cur;
        }
        cin >> n;
        while(n--){
            cin >> lo >> hi; lo--; hi--;
            if(grup[lo] == grup[hi]){
                cout << "-1 -1" << endl;
            }else{
                cout << awal[grup[lo]+1] << ' ' << awal[grup[lo]+1]+1 << endl;
            }
        }
        cout << endl;
    }
}
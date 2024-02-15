#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if(n%3){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m, h;
    cin >> n >> m;
    multiset<long long> s;
    for(int i=0; i<n; i++){
        cin >> h;
        s.insert(-h);
    }
    long long t[m];
    for(int i=0; i<m; i++){
        cin >> t[i];
    }
    for(int i=0; i<m; i++){
        if(s.lower_bound(-t[i]) == s.end()){
            cout << -1 << endl;
        }else{
            h = *(s.lower_bound(-t[i]));
            cout << -h << endl;
            s.erase(s.lower_bound(h));
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, x;
    cin >> n;
    set<long long> s;
    for(int i=0; i<n; i++){
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
}

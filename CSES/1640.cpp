#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, x, a;
    cin >> n >> x;
    set<pair<long long, long long> > s;
    set<pair<long long, long long> > :: iterator itr;
    bool found = false;
    for(int i=0; i<n && !found; i++){
        cin >> a;
        itr = s.upper_bound({x-a, 0});
        if(itr != s.end()){
            if((*itr).first == x-a){
                cout << (*itr).second << " " << i+1 << endl;
                found = true;
            }
        }
        s.insert({a, i+1});
    }
    if(!found){cout << "IMPOSSIBLE";}
}

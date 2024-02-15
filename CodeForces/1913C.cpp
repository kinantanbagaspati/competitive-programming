#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long m, t, v;
long long fi, se;
set<pll> neg, pos;
set<pll>::iterator itr;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> m;
    while(m--){
        cin >> t >> v; t--;
        if(t){
            itr = neg.begin();
            bool bisa = true;
            while(itr != neg.end() && bisa){
                bisa = bisa && (v/(-itr->first)*(-itr->first) <= itr->second);
                v %= (-itr->first);
                itr++;
            }
            if(bisa){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            v = (1<<v);
            itr = neg.lower_bound({-v, 0});
            if((itr != neg.end()) && (v <= itr->second)){ // nyentuh
                fi = -(itr->first); se = itr->second;
                // hapus
                neg.erase(itr);
                pos.erase({fi, se});
                se += v;
                itr = pos.lower_bound({v, 0});
                if(itr != pos.end() && itr->first <= se){
                    neg.erase({-(itr->first), itr->second});
                    pos.erase(itr);
                    se += itr->second;
                }
                // tambah
                neg.insert({-fi, se});
                pos.insert({fi, se});
            }else{
                neg.insert({-v, v});
                pos.insert({v, v});
            }
        }
    }
}
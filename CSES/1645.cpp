#include <bits/stdc++.h>
using namespace std;

long long n, x, ans[200069];
multiset<long long> neg;
multiset<long long> :: iterator itr;
pair<long long, long long> p, toSort[200069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> toSort[i].first;
        toSort[i].second = -i-1;
    }
    sort(toSort, toSort+n);
    for(int i=0; i<n; i++){
        itr = neg.upper_bound(toSort[i].second);
        if(itr == neg.end()){
            ans[-toSort[i].second-1] = 0;
        }else{
            ans[-toSort[i].second-1] = -(*itr);
        }
        neg.insert(toSort[i].second);
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }cout << endl;
}

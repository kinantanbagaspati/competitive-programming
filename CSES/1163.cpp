#include <bits/stdc++.h>
using namespace std;

long long x, n, ans[200069];
long long lo, hi, p;
multiset<long long> pos, neg, seg;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> x >> n;
    neg.insert(0);
    pos.insert(x);
    seg.insert(-x);
    for(int i = 0; i<n; i++){
        cin >> p;
        hi = *(pos.lower_bound(p));
        lo = -(*(neg.lower_bound(-p)));
        pos.insert(p);
        neg.insert(-p);
        seg.erase(seg.lower_bound(lo-hi));
        seg.insert(lo-p);
        seg.insert(p-hi);
        cout << -(*(seg.begin())) << " ";
    }cout << endl;
}

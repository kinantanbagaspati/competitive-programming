#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int n, x, y, z;
set<pii> xs, ys, zs;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        cin >> x >> y >> z;
        xs.insert({y,z});
        ys.insert({x,z});
        zs.insert({x,y});
    }
    int mnsz = max(max(xs.size(), ys.size()), zs.size());
    if(xs.size() == mnsz){
        cout << "X" << endl;
    }else if(ys.size() == mnsz){
        cout << "Y" << endl;
    }else{
        cout << "Z" << endl;
    }
}

/*
1->2: 0 1
2->3: 0 1
3->4: 1 0
4->5: 1 0
*/

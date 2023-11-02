#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long n, ssx = 0, sx = 0, x, ssy = 0, sy = 0, y;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        ssx += x*x;
        ssy += y*y;
        sx += x;
        sy += y;
    }
    cout << n*(ssx + ssy) - (sx*sx) - (sy*sy) << endl;
}

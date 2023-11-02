#include<bits/stdc++.h>
using namespace std;
#define pdd pair<double, double>

long long t;
double px, py, ax, ay, bx, by, ans;
double dis(pdd a, pdd b){
    double disx = a.first - b.first, disy = a.second - b.second;
    return sqrt(disx*disx + disy*disy);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> px >> py >> ax >> ay >> bx >> by;
        double disab = dis({ax, ay}, {bx, by})/2;
        ans = min(
            min(
                max(dis({ax, ay}, {0.0, 0.0}), dis({ax, ay}, {px, py})),
                max(dis({bx, by}, {0.0, 0.0}), dis({bx, by}, {px, py}))
            ),
            min(
                max(max(dis({ax, ay}, {0.0, 0.0}), dis({bx, by}, {px, py})), disab),
                max(max(dis({bx, by}, {0.0, 0.0}), dis({ax, ay}, {px, py})), disab)
            )
        );
        cout << ans << endl;
    }
}
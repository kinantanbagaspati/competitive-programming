#include <bits/stdc++.h>
using namespace std;

const int maxn = 1048576;
long long n, h[maxn];
// CHT purposes
long long grad[maxn], cons[maxn];
double range[maxn][2], shft[maxn][2];
double potong(double g0, double c0, double g1, double c1){
    //g0*x + c0 = g1*x + c1
    return (c1-c0)/(g0-g1);
}

int lifespan[maxn];
set<pair<int, int> > lifespans;
set<pair<pair<double, double>, int> > ranges;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> h[0];
    (hi+hj)*(j-i) = -i*hi (cons) + hi*j (shft) - i*hj (grad) + hj*j
    grad[0] = 0; cons[0] = 0;
    shft[0][0] = 0; shft[0][1] = 0;
    range[0][0] = -1e9; range[0][1] = 1e9;
    lifespan[0] = 1e9;
    for(int i=1; i<n; i++){
        cin >> h[i];
        //
        grad[i] = -i; cons[i] = -i*h[i];

    }

}

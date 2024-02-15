#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const int maxk = 1024, maxn = 4096;
int n, k, u[maxn][maxn], dp[maxn][maxn];
int dnc[maxk][maxn];

void dpdnc(int kid, int frlo, int frhi, int tolo, int tohi){
    int frmid = (frlo + frhi)/2, tomid = tolo;
    dnc[kid][frmid] = dnc[kid-1][tolo] + dp[frmid][tolo];
    for(int i=tolo; i<=min(frmid, tohi); i++){
        if(dnc[kid][frmid] > dnc[kid-1][i] + dp[frmid][i]){
            dnc[kid][frmid] = dnc[kid-1][i] + dp[frmid][i];
            tomid = i;
        }
    }
    if(frlo < frmid){
        dpdnc(kid, frlo, frmid-1, tolo, tomid);
    }
    if(frmid < frhi){
        dpdnc(kid, frmid+1, frhi, tomid, tohi);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        //cout << "u:";
        for(int j=1; j<=n; j++){
            cin >> u[i][j];
            u[i][j] += u[i-1][j] + u[i][j-1] - u[i-1][j-1];
            //cout << ' ' << u[i][j];
        } //cout << endl;
        //cout << "dp: ";
        for(int j=0; j<=i; j++){
            dp[i][j] = u[i][i] - u[i][j] - u[j][i] + u[j][j];
            //cout << ' ' << dp[i][j];
        } //cout << endl;
    } // skrg dp[i][j] nyimpen cost bawa org j...(i-1) 0-index
    
    dpdnc(1, 0, n, 0, 0);
    for(int i=2; i<=k; i++){
        dpdnc(i, 0, n, 0, n);
    }
    cout << dnc[k][n]/2 << endl;
}
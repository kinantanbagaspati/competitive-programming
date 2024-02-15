#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072, maxk = 24;
int n, k, a[maxn], freq[maxn];
long long cost=0, dp[maxk][maxn]; //dp[i][j] nyimpen pembagian a[0...(j-1)] dalam i klmpk

void dpdnc(int kid, int frlo, int frhi, int tolo, int tohi){ //inklusif
    //cout << "dpdnc " << kid << " (" << frlo << ',' << frhi << ") (" << tolo << ',' << tohi << ')' << endl;
    //cout << "skrg cost a["<< tolo << "...(" << frlo-1 << ")] = " << cost <<endl;
    
    // init freq sama cost
    int frmid = (frlo + frhi)/2, tomid = tolo;
    for(int i=frlo; i<frmid; i++){
        cost += freq[a[i]]; freq[a[i]]++;
    }
    dp[kid][frmid] = cost + dp[kid-1][tolo];

    // itung min
    for(int i=tolo; i<min(frmid, tohi); i++){
        freq[a[i]]--; cost -= freq[a[i]];
        if(dp[kid][frmid] > dp[kid-1][i+1] + cost){
            dp[kid][frmid] = dp[kid-1][i+1] + cost;
            tomid = i+1;
        }
    }
    //cout << "fr to: " << frmid << " " << tomid << endl;
    // skrg cost a[min(frmid, tohi)...(frmid-1)]
    for(int i=min(frmid, tohi)-1; i>=tolo; i--){
        cost += freq[a[i]]; freq[a[i]]++;
    }
    for(int i=frmid-1; i>=frlo; i--){
        freq[a[i]]--; cost -= freq[a[i]];
    }
    // skrg cost a[tolo...(frlo-1)]

    if(frlo < frmid){
        dpdnc(kid, frlo, frmid-1, tolo, tomid);
        cost += freq[a[frmid-1]]; freq[a[frmid-1]]++;
    }else{
        for(int i=tolo; i<tomid; i++){
            freq[a[i]]--; cost -= freq[a[i]];
        }
    } 
    //skrg cost a[tomid...(frmid-1)]
    if(frmid < frhi){
        cost += freq[a[frmid]]; freq[a[frmid]]++;
        dpdnc(kid, frmid+1, frhi, tomid, tohi);
    }else{
        for(int i=tomid; i<tohi; i++){
            freq[a[i]]--; cost -= freq[a[i]];
        }
    }
    // akhirnya cost a[tohi...(frhi-1)]
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    dpdnc(1, 0, n, 0, 0);
    for(int j=0; j<=n; j++){
        freq[j] = 0; //cout << dp[1][j] << ' ';
    } //cout << endl << endl;
    //cout << endl << "cost: " << cost << endl << endl;
    for(int i=2; i<=k; i++){
        cost = 0;
        dpdnc(i, 0, n, 0, n);
        for(int j=0; j<=n; j++){
            freq[j] = 0; //cout << dp[i][j] << ' ';
        } //cout << endl << endl;
        //cout << endl << "cost: " << cost << endl << endl;
    }
    cout << dp[k][n] << endl;
}

#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072, maxp=128;
long long n, m, p, h, pad;
long long d[maxn], t[maxn], dp[maxp][maxn];
long long stids[maxn], starts[maxn], nbst=0, stidx=0;

long long getY(long long pid, long long mid, long long x){
    return (mid+1)*x - d[mid] - dp[pid][mid];
}
long long getCut(long long pid, long long loid, long long hiid){
    // cari minimal x shg (hiid+1)*x - d[hiid] - dp[pid][hiid] >= (loid+1)*x - d[loid] - dp[pid][loid]
    return (d[hiid] + dp[pid][hiid] - d[loid] - dp[pid][loid]) / (hiid-loid);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> p;
    for(long long i=1; i<n; i++){
        cin >> d[i]; d[i] += d[i-1];
    }
    pad = d[n-1];
    for(long long i=0; i<m; i++){
        cin >> h >> t[i]; t[i] += pad-d[h-1];
    }
    //cout << "kelar input" << endl;
    sort(t, t+m);
    // pake d buat prefix sum t
    d[0] = t[0];
    //cout << "0: " << t[0] << ' ' << d[0] << endl;
    for(long long i=1; i<m; i++){
        d[i] = d[i-1] + t[i];
        //cout << i << ": " << t[i] << ' ' << d[i] << endl;
    }

    // populate pertama
    h = 1e18;
    //cout << "dari " << idx << ':';
    for(long long i=0; i<m; i++){
        dp[0][i] = t[i]*(i+1) - d[i];
        //cout << ' ' << dp[0][i];
    } //cout << endl;
    for(long long i=1; i<min(m, p); i++){
        // isi stack
        stids[0] = i-1;
        starts[0] = 0;
        nbst = 1;
        stidx = 0;
        //cout << "dari " << idx+i << ':' << endl;
        // cobain brute force
        /*for(long long j=i; j<m; j++){
            dp[i][j] = 1e18;
            for(long long k=i-1; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i-1][k] + t[j] * (j-k) - d[j] + d[k]);
            }
            //cout << dp[i][j] << ' ';
        } //cout << endl;
        h = min(dp[i][m-1], h); continue;*/
        for(long long j=i; j<m; j++){
            // update dp
            stidx = min(nbst-1, stidx);
            while(stidx < nbst-1 && t[j] >= starts[stidx+1]){
                stidx++;
            }
            /*cout << "stack:";
            for(long long k=0; k<nbst; k++){
                cout << ' ' << stids[k];
            } 
            cout << endl << "start:";
            for(long long k=0; k<nbst; k++){
                cout << ' ' << starts[k];
            }
            cout << endl << "stidx: " << stidx << endl;*/
            dp[i][j] = t[j] * (j+1) - d[j] - getY(i-1, stids[stidx], t[j]);
            //cout << dp[i][j] << ' ';

            // update stack
            while(nbst > 0 && getY(i-1, j, starts[nbst-1]) >= getY(i-1, stids[nbst-1], starts[nbst-1])){
                nbst--;
            }
            stids[nbst] = j;
            if(nbst > 0){
                starts[nbst] = getCut(i-1, stids[nbst-1], j);
            }else{
                starts[nbst] = 0;
            }
            nbst++;
        }
        //cout << endl << endl;
        h = min(dp[i][m-1], h); 
    }
    cout << h << endl;
}

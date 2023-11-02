#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 1048576;
long long t, n, a, freq[maxn], ans;
vector<long long> factors[maxn];
bool ada[maxn];

void sieve(){
    for(int i=1; i<maxn; i++){
        for(int j=i; j<maxn; j+=i){
            factors[j].push_back(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sieve();
    cin >> t;
    while(t--){
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> a;
            for(int i=0; i<factors[a].size(); i++){
                freq[factors[a][i]]++;
            }
            ada[a] = true;
        }
        ans = 0;
        for(int i=n; i>0; i--){
            freq[i] = freq[i] * (freq[i]-1) / 2;
            for(int j=i*2; j<=n; j+=i){
                freq[i] -= freq[j];
            }
            //cout << "freq " << i << ": " << freq[i] << endl;
            bool tambah = true;
            for(int j=0; j<factors[i].size(); j++){
                tambah = tambah && (!ada[factors[i][j]]);
            }
            if(tambah){
                ans += freq[i];
            }
        }
        cout << ans << endl;
        // beresin
        for(int i=1; i<=n; i++){
            freq[i] = 0;
            ada[i] = false;
        }
    }
}

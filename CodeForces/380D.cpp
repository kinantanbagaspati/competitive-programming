#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn=131072, mod=1e9+7;
long long fac[maxn*2], ifac[maxn*2];

long long pangkat(long long a, long long b){
    a%=mod; b%=(mod-1);
    long long res = 1;
    while(b>0){
        if(b%2){res = res*a%mod;}
        a = a*a%mod; b /= 2;
    }
    return res;
}
void initFac(){
    fac[0] = 1;
    for(int i=1; i<maxn*2; i++){
        fac[i] = fac[i-1]*i%mod;
    }
    ifac[maxn*2-1] = pangkat(fac[maxn*2-1], mod-2);
    for(int i=maxn*2-1; i>0; i--){
        ifac[i-1] = ifac[i]*i%mod;
    }
}
long long choose(long long a, long long b){
    if(b<0 || b>a){
        return 0;
    }
    return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

long long n, a[maxn], pw[maxn];
long long lo, hi, lolo, hihi;
vector<pair<int, int> > srt;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    initFac();
    cin >> n;
    pw[0] = 1;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] > 0){
            srt.push_back({a[i], i});
        }
        pw[i+1] = pw[i] * 2 % mod;
    }
    if(srt.size()==0){
        cout << pw[n-1] << endl;
        return 0;
    }
    sort(srt.begin(), srt.end());
    long long ans = 0, cur;
    // kiri
    lo = srt[0].second - srt[0].first + 1;
    hi = srt[0].second;
    if(0 <= lo && hi < n){
        cur = pw[max(0LL, hi-lo-1)];
    }else{
        cur = 0;
    }
    //cout << "kiri: " << lo << '-' << hi << endl;
    for(int i=1; i<srt.size(); i++){
        lolo = srt[i].second - srt[i].first + 1;
        hihi = srt[i].second - 1;
        if(0 <= lolo && lolo <= lo && hi <= hihi){
            cur = cur * choose(lo-lolo+hihi-hi, lo-lolo) % mod;
            lo = lolo; hi = hihi+1;
            continue;
        }
        lolo = srt[i].second + 1;
        hihi = srt[i].second + srt[i].first - 1;
        if(lolo <= lo && hi <= hihi && hihi < n){
            cur = cur * choose(lo-lolo+hihi-hi, lo-lolo) % mod;
            lo = lolo-1; hi = hihi;
            continue;
        }
        cur = 0;
    }
    ans = (cur * choose(lo+n-1-hi, lo) + ans) % mod;
    if(srt[0].first == 1){
        cout << ans << endl;
        return 0;
    }

    // kanan
    lo = srt[0].second;
    hi = srt[0].second + srt[0].first - 1;
    if(0 <= lo && hi < n){
        cur = pw[max(0LL, hi-lo-1)];
    }else{
        cur = 0;
    }
    for(int i=1; i<srt.size(); i++){
        lolo = srt[i].second - srt[i].first + 1;
        hihi = srt[i].second - 1;
        if(0 <= lolo && lolo <= lo && hi <= hihi){
            cur = cur * choose(lo-lolo+hihi-hi, lo-lolo) % mod;
            lo = lolo; hi = hihi+1;
            continue;
        }
        lolo = srt[i].second + 1;
        hihi = srt[i].second + srt[i].first - 1;
        if(lolo <= lo && hi <= hihi && hihi < n){
            cur = cur * choose(lo-lolo+hihi-hi, lo-lolo) % mod;
            lo = lolo-1; hi = hihi;
            continue;
        }
        cur = 0;
    }
    ans = (cur * choose(lo+n-1-hi, lo) + ans) % mod;
    cout << ans << endl;
}
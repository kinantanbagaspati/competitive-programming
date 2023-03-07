#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072, maxm=1e11;
long long n, kanan[maxn], pos[maxn], sz = 0;
long long cons[maxn];
pll info[maxn];

long long getY(int stckidx, int x){
    int p = pos[stckidx];
    return cons[p] + (info[p].second-1)/ x * info[p].first;
}

long long motong(){// kapan batas atas kurva sz yg lebih min dari kurva sz-1
    long long lo = -maxm, hi = maxm+1;

}
long long getMinY(int x){
    int lo = 0, hi = sz, mid;
    while(hi-lo > 1){
        mid = (lo+hi)/2;
        if(x <= kanan[sz-1-mid]){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    return getY(lo, x);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> info[0].first; info[0].second = -1;
    for(int i=1; i<=n; i++){
        cin >> info[i].first >> info[i].second;
    }
    sort(info, info+(n+1));
    int i=n;
    while(info[i] >= 0){
        // itung cons
        if(i == n){ // stack masih kosong
            cons[i] = 0;
        }else{
            cons[i] = getMinY(info[i].first);
        }
        pos[sz] = i;
        if(sz>0 && getY(sz, -maxm) < getY(sz-1, -maxm)){ // masukin
            while(sz>0 && getY(sz, kanan[sz-1]) < getY(sz-1, kanan[sz-1])){
                pos[sz]
            }

        }
        // hapus
        while(sz>0 && ){

        }
        if(){

        }

        i--;
    }
}

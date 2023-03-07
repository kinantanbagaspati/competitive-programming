#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069;
long long n, k, x[maxn];
set<pair<long long, long long> > s;
set<pair<long long, long long> > :: iterator itr, other;
long long sz = 0, ans;

void addel(pair<long long, long long> p){
    s.insert(p);
    long long old = (*itr).first;
    ans += abs(p.first - old);

    if(p < *itr){
        if(sz%2){itr--;}
    }else{
        if(!(sz%2)){
            itr++; ans -= (*itr).first - old;
        }
    }
    sz++;
}

void delel(pair<long long, long long> p){
    long long old = (*itr).first;
    if(p < *itr){
        if(!(sz%2)){itr++;}
    }else if(p > *itr){
        if(sz%2){
            itr--; ans += old - (*itr).first;
        }
    }else if(sz%2){
        itr--; ans += old - (*itr).first;
    }else{
        itr++;
    }
    s.erase(p);
    ans -= abs(p.first - (*itr).first);
    sz--;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> x[i];
        if(i<k){
            s.insert({x[i],i});
        }
    }
    itr = s.begin();
    for(int i=1; i<(k+1)/2; i++){itr++;}
    sz = k; ans = 0;
    for(int i=0; i<k; i++){
        ans += abs(x[i] - (*itr).first);
    }
    cout << ans;
    for(int i=k; i<n; i++){
        addel({x[i], i});
        //cout << endl << ans;
        delel({x[i-k], i-k});
        cout << " " << ans;
    }
    cout << endl;
}

#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069;
long long n, k, x[maxn];
set<pair<long long, long long> > s;
set<pair<long long, long long> > :: iterator itr, other;
long long sz = 0;

void addel(pair<long long, long long> p){
    s.insert(p);
    if(p < *itr){
        if(sz%2){itr--;}
    }else{
        if(!(sz%2)){itr++;}
    }
    sz++;
}

void delel(pair<long long, long long> p){
    if(p < *itr){
        if(!(sz%2)){itr++;}
    }else if(p > *itr){
        if(sz%2){itr--;}
    }else if(sz%2){
        itr--;
    }else{
        itr++;
    }
    s.erase(p);
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
    sz = k;
    cout << (*itr).first;
    for(int i=k; i<n; i++){
        addel({x[i], i});
        delel({x[i-k], i-k});
        cout << " " << (*itr).first;
    }
    cout << endl;
}

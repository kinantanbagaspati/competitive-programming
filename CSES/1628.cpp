#include <bits/stdc++.h>
using namespace std;

long long n, x, t[40];
long long fh[(1<<20)], sh[(1<<20)];
pair<long long, long long> fp[(1<<20)], sp[(1<<20)];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> t[i];
    }
    long long mx = (1 << (n/2));
    for(int i=0; i<mx; i++){
        long long cp = i, sum = 0;
        for(int j=0; j<n/2; j++){
            if(cp%2){
                sum += t[j];
            }
            cp /= 2;
        }
        fh[i] = sum;
    }
    sort(fh, fh+mx);
    long long mx1 = 1;
    fp[0] = {fh[0], 1};
    for(int i=1; i<mx; i++){
        if(fh[i] == fp[mx1-1].first){
            fp[mx1-1].second++;
        }else{
            fp[mx1] = {fh[i], 1};
            mx1++;
        }
    }
    /*
    for(int i=0; i<mx1; i++){
        cout << fp[i].first << " " << fp[i].second << endl;
    }cout << endl;
    */
    long long ans = 0;
    mx = (1 << (n - n/2));
    for(int i=0; i<mx; i++){
        long long cp = i, sum = 0;
        for(int j=n/2; j<n; j++){
            if(cp%2){
                sum -= t[j];
            }
            cp /= 2;
        }
        sh[i] = sum;
    }
    sort(sh, sh+mx);
    long long mx2 = 1;
    sp[0] = {sh[0], 1};
    for(int i=1; i<mx; i++){
        if(sh[i] == sp[mx2-1].first){
            sp[mx2-1].second++;
        }else{
            sp[mx2] = {sh[i], 1};
            mx2++;
        }
    }
    /*
    for(int i=0; i<mx2; i++){
        cout << sp[i].first << " " << sp[i].second << endl;
    }cout << endl;
    */
    long long itr1 = 0;
    long long itr2 = 0;
    while(itr1 < mx1 && itr2 < mx2){
        //cout << itr1->first << " " << itr2->first << endl;
        if(fp[itr1].first - sp[itr2].first == x){
            ans += fp[itr1].second * sp[itr2].second;
        }
        if(fp[itr1].first - sp[itr2].first > x){
            itr2++;
        }else{
            itr1++;
        }
    }

    cout << ans << endl;
}

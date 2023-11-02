#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const int maxn = 262144;
int n, m, k[maxn], sum=0, cursum;
pii dj[maxn], akhir[maxn];
int lo, mid, hi;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> k[i]; sum += k[i];
    }
    for(int i=0; i<m; i++){
        cin >> dj[i].first >> dj[i].second; dj[i].second--;
    }
    sort(dj, dj+m);
    /*for(int i=0; i<m; i++){
        cout << "(" << dj[i].first << "," << dj[i].second << ") ";
    } cout << endl;*/
    
    lo = 0; hi = sum*2;
    while(hi-lo>1){
        mid = (lo+hi)/2;
        //cout << "lmh " << lo << " " << mid << " " << hi << endl;
        for(int i=0; i<n; i++){
            akhir[i] = {0, i};
        } cursum = 0;
        for(int i=0; i<m && dj[i].first <= mid; i++){
            akhir[dj[i].second].first = dj[i].first;
        }
        sort(akhir, akhir+n);
        /*for(int i=0; i<n; i++){
            cout << "(" << akhir[i].first << "," << akhir[i].second << ") ";
        } cout << endl;*/
        int money = 0, idx = 0;
        while(idx < n && akhir[idx].first == 0){
            idx++;
        }
        for(int i=1; i<=mid; i++){
            money++;
            while(idx < n && akhir[idx].first == i){
                int beli = min(k[akhir[idx].second], money);
                cursum += beli; 
                money -= beli;
                idx++;
            }
        }
        //cout << sum << " " << cursum << " " << money << endl;

        if(2*(sum - cursum) > money){
            lo = mid;
        }else{
            hi = mid;
        }
    }
    cout << hi << endl;
}
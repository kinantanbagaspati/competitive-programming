#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069, sqn = 450;
long long n, q;
long long x[maxn], compx[maxn], curcom = 0, freq[maxn];
pair<long long, long long> srt[maxn];
long long ranges[maxn][2], ans[maxn];
pair<pair<long long, long long>, long long> pplll[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for(int i=0; i<n; i++){
        cin >> x[i];
        srt[i] = {x[i], i};
    }
    sort(srt, srt+n);
    compx[srt[0].second] = curcom;
    for(int i=1; i<n; i++){
        if(srt[i].first != srt[i-1].first){
            curcom++;
        }
        compx[srt[i].second] = curcom;
    }
    /*
    for(int i=0; i<n; i++){
        cout << compx[i] << " ";
    }cout << endl;
    */
    for(int i=0; i<q; i++){
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][0]--; ranges[i][1]--;
        pplll[i] = {{ranges[i][0]/sqn, ranges[i][1]}, i};
    }
    sort(pplll, pplll+q);
    long long lo = 0, hi = -1, id;
    long long cur = 0;
    for(int i=0; i<q; i++){
        id = pplll[i].second;
        //cout << lo << " " << hi << endl;
        while(ranges[id][0] < lo){
            lo--;
            if(freq[compx[lo]] == 0){cur++;}
            freq[compx[lo]]++;
        }
        while(ranges[id][1] > hi){
            hi++;
            if(freq[compx[hi]] == 0){cur++;}
            freq[compx[hi]]++;
        }
        //cout << lo << " " << hi << endl;
        while(ranges[id][0] > lo){
            freq[compx[lo]]--;
            if(freq[compx[lo]] == 0){cur--;}
            lo++;
        }
        while(ranges[id][1] < hi){
            freq[compx[hi]]--;
            if(freq[compx[hi]] == 0){cur--;}
            hi--;
        }
        //cout << lo << " " << hi << endl;
        ans[id] = cur;
        //cout << endl;
    }
    for(int i=0; i<q; i++){
        cout << ans[i] << endl;
    }
}

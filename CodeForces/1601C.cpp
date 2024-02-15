#include<bits/stdc++.h>
using namespace std;
#define pll pair<int, int>

int t, n, m, a[(1<<20)], b[(1<<20)];
pair<int, int> srt[(1<<21)];
vector<int> selip[(1<<20)];
int segtree[(1<<22)], pwn, nbcomp;

void build(){
    pwn = 1;
    //cout << "nbcomp: " << nbcomp << endl;
    while(pwn <= nbcomp){pwn*=2;}
    for(int i=0; i<pwn*2; i++){
        segtree[i] = 0;
    }
}
void update(int idx, int val){
    idx += pwn;
    while(idx > 0){
        segtree[idx] += val; idx /= 2;
    }
}
int query(int lo, int hi){
    lo += pwn; hi += pwn;
    int ret = 0;
    while(lo<=hi){
        if(lo%2==1){
            ret += segtree[lo]; 
        } lo = (lo+1)/2;
        if(hi%2==0){
            ret += segtree[hi];
        } hi = (hi-1)/2;
    }
    return ret;
}

void dp(int lon, int hin, int lom, int him){
    if(lom > him){return;}
    int midm = (lom+him)/2;
    // ngitung midm
    int cur=0, sum=0, mincur=0, point = lon;
    for(int i=lon; i<hin; i++){
        sum += (b[midm] > a[i]);
        if(b[midm] < a[i]){
            cur++;
        }else if(b[midm] > a[i]){
            cur--;
        }
        if(cur < mincur){
            mincur = cur;
            point = i+1;
        }
    }
    //cout << midm << " nunjuk " << point << " nambah " << sum << "+" << mincur << endl;
    dp(lon, point, lom, midm-1); 
    selip[point].push_back(b[midm]);
    dp(point, hin, midm+1, him);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> a[i]; selip[i].clear();
            srt[i] = {a[i], i};
        }
        selip[n].clear();
        for(int i=0; i<m; i++){
            cin >> b[i];
            srt[n+i] = {b[i], n+i};
        }
        sort(srt, srt+n+m);
        int cur = -1; nbcomp = -1;
        for(int i=0; i<n+m; i++){
            if(srt[i].first != cur){
                cur = srt[i].first; nbcomp++;
            }
            if(srt[i].second < n){
                a[srt[i].second] = nbcomp;
            }else{
                b[srt[i].second - n] = nbcomp;
            }
        }

        sort(b, b+m); 
        dp(0, n, 0, m-1);
        build();
        long long ans = 0;
        for(int i=0; i<n; i++){
            //cout << "diselipin";
            for(int j=0; j<selip[i].size(); j++){
                //cout << "query " << selip[i][j]+1 << "-" << pwn-1 << endl;
                ans += (long long) query(selip[i][j]+1, pwn-1);
                //cout << " " << selip[i][j];
            } //cout << endl;
            for(int j=0; j<selip[i].size(); j++){
                //cout << "update " << selip[i][j] << "+1" << endl;
                update(selip[i][j], 1);
            }
            ans += query(a[i]+1, pwn-1);
            update(a[i], 1);
            //cout << "query " << a[i]+1 << "-" << pwn-1 << endl << "update " << a[i] << "+1" << endl;
            //cout << "ans = " << ans << endl << endl;
            //cout << "sebelum " << a[i] << ", ans = " << ans << endl;
        }
        for(int i=0; i<selip[n].size(); i++){
            ans += (long long) query(selip[n][i]+1, pwn-1);
        }
        cout << ans << endl;
    }
}

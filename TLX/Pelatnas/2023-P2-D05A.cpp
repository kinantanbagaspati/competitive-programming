#include <bits/stdc++.h>
using namespace std;

const long long maxnk = 1048576;
long long n, k, r, ans=0;
vector<pair<long long, long long> > req[maxnk];
long long curPoint[maxnk], idxTopic[maxnk], deg[maxnk];
vector<long long> rew[maxnk];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    // ngurus requirements
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cin >> r;
            req[j].push_back({r, i});
        }
    }
    for(int i=0; i<k; i++){
        sort(req[i].begin(), req[i].end());
    }

    // ngurus reward
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            cin >> r;
            rew[i].push_back(r);
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            while(idxTopic[j] < n && curPoint[j] >= req[j][idxTopic[j]].first){
                long long mod = req[j][idxTopic[j]].second;
                deg[mod]--;
                if(deg[mod] == -k){
                    for(int m=0; m<k; m++){
                        curPoint[m] += rew[mod][m];
                    } ans++;
                }
                idxTopic[j]++;
            }
        }    
    }
    cout << ans << endl;

    return 0;
}
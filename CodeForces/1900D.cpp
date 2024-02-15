#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 131072;
long long t, n, a[maxn], ans[maxn], answer;
vector<long long> facs[maxn], idxs[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=1; i<maxn; i++){
        for(int j=i; j<maxn; j+=i){
            facs[j].push_back(i);
        }
    }
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i]; 
        }
        sort(a, a+n);
        for(int i=0; i<n; i++){
            for(int j=0; j<facs[a[i]].size(); j++){
                idxs[facs[a[i]][j]].push_back(i);
            }
        }
        answer = 0;
        for(int i=maxn-1; i>0; i--){
            for(int j=0; j<idxs[i].size(); j++){
                ans[i] += (n-1-idxs[i][j]) * j;
            }
            answer += ans[i] * i;
            idxs[i].clear();
            for(int j=0; j<facs[i].size(); j++){
                ans[facs[i][j]] -= ans[i];
            }
        }
        cout << answer << endl;
    } 
}
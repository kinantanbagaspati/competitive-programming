#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 64, maxm = 4094;
long long t, n, m, uv;
long long mindeg, ans[maxm];
vector<long long> al[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            al[i].clear();
        }
        for(int i=0; i<m; i++){
            cin >> uv; al[uv].push_back(i);
            cin >> uv; al[uv].push_back(i);
            ans[i] = 1;
        }
        mindeg = 1;
        for(int i=2; i<=n; i++){
            if(al[i].size() < al[mindeg].size()){
                mindeg = i;
            }
        }
        if(al[mindeg].size() == n-1){
            cout << 3 << endl;
            ans[al[mindeg][0]] = 3;
        }else{
            cout << 2 << endl;
            ans[al[mindeg][0]] = 2;
        }
        for(int i=1; i<al[mindeg].size(); i++){
            ans[al[mindeg][i]] = 2;
        }
        for(int i=0; i<m; i++){
            cout << ans[i] << " ";
        }cout << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

const int maxn = 333;
bool iswap = false, mulai = false;
int n, m, a[maxn][maxn];
int cur=0, mincur=0, minx=0, miny=0;
vector<pair<int, int> > ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }
    if(n*m%2){
        cout << -1 << endl; return 0;
    }
    if(n%2){
        for(int i=0; i<maxn; i++){
            for(int j=0; j<i; j++){
                swap(a[i][j],a[j][i]);
            }
        }
        swap(n, m); iswap = true;
    }
    ans.push_back({0,0});
    cur += a[0][0];
    for(int i=0; i<n; i++){
        if(i%2){
            for(int j=m-1; j>0; j--){
                if(cur < mincur){
                    mincur = cur; minx = i; miny = j;
                }
                ans.push_back({i,j});
                cur += a[i][j];
            }
        }else{
            for(int j=1; j<m; j++){
                if(cur < mincur){
                    mincur = cur; minx = i; miny = j;
                }
                ans.push_back({i,j});
                cur += a[i][j];
            }
        }
    }
    for(int i=n-1; i>0; i--){
        if(cur < mincur){
            mincur = cur; minx = i; miny = 0;
        }
        ans.push_back({i,0});
        cur += a[i][0];
    }
    if(cur < 0){
        cout << -1 << endl; return 0;
    }
    for(int i=0; i<ans.size(); i++){
        mulai = mulai || (ans[i].first==minx && ans[i].second==miny);
        if(mulai){
            if(iswap){
                cout << ans[i].second+1 << ' ' << ans[i].first+1 << endl;
            }else{
                cout << ans[i].first+1 << ' ' << ans[i].second+1 << endl;
            }
        }
    }
    mulai = false;
    for(int i=0; i<ans.size(); i++){
        mulai = mulai || (ans[i].first==minx && ans[i].second==miny);
        if(!mulai){
            if(iswap){
                cout << ans[i].second+1 << ' ' << ans[i].first+1 << endl;
            }else{
                cout << ans[i].first+1 << ' ' << ans[i].second+1 << endl;
            }
        }
    }
}
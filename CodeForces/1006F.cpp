#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long n, m, k, board[32][32], ans = 0;
vector<pll> vals[64];
map<pll, long long> valMap;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
    vals[0].push_back({board[0][0], 0});
    for(int i=0; i<(n+m-2)/2; i++){
        for(int j=0; j<vals[i].size(); j++){
            long long val = vals[i][j].first, row = vals[i][j].second;
            if(row < n-1){
                vals[i+1].push_back({val ^ board[row+1][i-row], row+1});
            }
            if(i-row < m-1){
                vals[i+1].push_back({val ^ board[row][i-row+1], row});
            }
        }
    }
    //cout << "atas" << endl;
    for(int i=0; i<vals[(n+m-2)/2].size(); i++){
        //cout << vals[(n+m-2)/2][i].first << " " << vals[(n+m-2)/2][i].second << endl;
        valMap[vals[(n+m-2)/2][i]]++;
    }
    vals[(n+m-2)/2].clear();
    
    vals[n+m-2].push_back({board[n-1][m-1], n-1});
    for(int i=n+m-2; i>(n+m-2)/2; i--){
        for(int j=0; j<vals[i].size(); j++){
            long long val = vals[i][j].first, row = vals[i][j].second;
            if(row > 0){
                vals[i-1].push_back({val ^ board[row-1][i-row], row-1});
            }
            if(i-row > 0){
                vals[i-1].push_back({val ^ board[row][i-row-1], row});
            }
        }
    }
    //cout << "bawah" << endl;
    for(int i=0; i<vals[(n+m-2)/2].size(); i++){
        //cout << vals[(n+m-2)/2][i].first << " " << vals[(n+m-2)/2][i].second << endl;
        long long val = vals[(n+m-2)/2][i].first, row = vals[(n+m-2)/2][i].second;
        ans += valMap[{val ^ k ^ board[row][(n+m-2)/2 - row], row}];
    }
    cout << ans << endl;
}
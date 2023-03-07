#include <bits/stdc++.h>
using namespace std;

char c[4] = {'A', 'C', 'G', 'T'};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    vector<int> occ[4];
    for(int i=0; i<s.length(); i++){
        for(int j=0; j<4; j++){
            if(s[i] == c[j]){occ[j].push_back(i);}
        }
    }
    int idx[4], curidx=-1, nextidx;
    for(int i=0; i<4; i++){idx[i]=0;}
    string ans = "", cur = " ";
    bool notfound = true;
    while(notfound){
        nextidx = curidx;
        for(int j=0; j<4 && notfound; j++){
            while(idx[j]<occ[j].size() && occ[j][idx[j]]<=curidx){
                idx[j]++;
            }
            if(idx[j]==occ[j].size()){
                if(notfound){
                    notfound = false;
                    cur[0] = c[j];
                }
            }else if(occ[j][idx[j]] > nextidx){
                cur[0] = c[j];
                nextidx = occ[j][idx[j]];
            }
        }
        ans += cur;
        curidx = nextidx;
    }
    cout << ans << endl;
}

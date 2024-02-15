#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int ones, twos;
int ans[262144][3], nbnodes=1;

bool dfs(int sum){
    int node = nbnodes; nbnodes++; 
    if(sum == 1){
        ans[node][0] = 1; ones--;
        return ones >= 0;
    }else if(sum == 2){
        if(twos > 0){
            ans[node][0] = 2; twos--;
            return twos >= 0;
        }else{
            ans[node][0] = 1; ones--;
            ans[node][1] = nbnodes;
            return dfs(1);
        }
    }else if(sum == 3){
        if(twos > 0){
            ans[node][0] = 2; twos--;
            ans[node][1] = nbnodes;
            return dfs(1);
        }else{
            ans[node][0] = 1; ones--;
            ans[node][1] = nbnodes; ans[node][2] = nbnodes+1;
            return dfs(1) && dfs(1);
        }
    }
    if(twos > 0){
        ans[node][0] = 2; twos--;
        bool ret = true;
        ans[node][1] = nbnodes;
        ret = ret && dfs((sum-1)/2);
        ans[node][2] = nbnodes;
        ret = ret && dfs((sum-2)/2);
        return ret;
    }else{
        ans[node][0] = 1; ones--;
        ans[node][1] = nbnodes; dfs(sum/2);
        ans[node][2] = nbnodes; dfs((sum-1)/2);
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> ones >> twos;
    if(dfs(ones + twos*2)){
        for(int i=1; i<nbnodes; i++){
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
        }
    }else{
        cout << -1 << endl;
    }
}
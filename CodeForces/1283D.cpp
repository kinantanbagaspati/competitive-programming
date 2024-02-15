#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = 262144;
int n, m, x[maxn], adj[maxn][2];
long long sum=0;
vector<int> ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> x[i];
        adj[i][0] = i-1; adj[i][1] = i+1;
    }
    adj[n][0] = n-1; adj[n][1] = n+1;
    sort(x, x+n);
    for(int dis=1; m>0; dis++){
        if(m>0){
            ans.push_back(x[0]-dis); 
            sum += dis; m--;
        }
        for(int i=adj[0][1]; i<n && m>0; i=adj[i][1]){
            if(x[i-1]+dis < x[i]-dis){
                if(m>0){ans.push_back(x[i-1]+dis); sum += dis; m--;}
                if(m>0){ans.push_back(x[i]-dis); sum += dis; m--;}
            }else if(x[i-1]+dis > x[i]-dis){
                adj[adj[i][0]][1] = adj[i][1];
                adj[adj[i][1]][0] = adj[i][0];
            }else{
                if(m>0){ans.push_back(x[i]-dis); sum += dis; m--;}
            }
        }
        if(m>0){
            ans.push_back(x[n-1]+dis); 
            sum += dis; m--;
        }
    }
    cout << sum << endl;
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << ' ';
    } cout << endl;
}

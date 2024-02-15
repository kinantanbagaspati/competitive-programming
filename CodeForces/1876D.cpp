#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 262144, mod = 998244353, inv2 = (mod+1)/2;
long long n, a[maxn], ans = 1, sama = 0;
long long q[maxn], head = 0, tail = 0;
bool vis[maxn];
vector<long long> al[maxn];

void dfs(long long node){
    vis[node] = true;
    for(int i=0; i<al[node].size(); i++){
        if(!vis[al[node][i]]){
            dfs(al[node][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(head == tail){
            q[tail] = a[i]; tail++;
        }else if(q[head] == a[i]){
            head++;
        }else{
            q[tail] = a[i];
            al[q[tail]].push_back(q[head]);
            al[q[head]].push_back(q[tail]);
            tail++;
        }
    }
    sama = (head == tail);
    sort(a, a+n);
    for(int i=0; i<n; i++){
        if(i==0 || a[i] != a[i-1]){
            ans = ans * 2 % mod;
            if(!vis[a[i]]){
                dfs(a[i]); sama = sama * 2 % mod;
            }
        }
    }
    cout << (ans + mod - sama) * inv2 % mod << endl;
}

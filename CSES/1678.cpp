#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> al[100069], ans, stck;
bool vis[100069];
set<long long> s;
stack<long long> st;

void init(long long n, long long m){
    for(int i=1; i<=n; i++){
        vis[i] = false;
    }
    long long a, b;
    while(m--){
        cin >> a >> b;
        al[a].push_back(b);
    }
    ans.clear();
    s.clear();
}

bool dfs(long long node){
    vis[node] = true;
    st.push(node);
    s.insert(node);
    bool found = false;
    for(int i=0; i<al[node].size() && !found; i++){
        if(s.count(al[node][i]) > 0){
            //ketemu
            while(st.top() != al[node][i]){
                ans.push_back(st.top());
                st.pop();
            }
            ans.push_back(st.top());
            found = true;
        }else if(!vis[al[node][i]]){
            found = dfs(al[node][i]);
        }
    }
    if(!st.empty()){
        st.pop();
    }
    s.erase(node);
    return found;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    init(n, m);

    bool found = false;
    for(int i=1; i<=n && !found; i++){
        if(!vis[i]){
            found = dfs(i);
        }
    }
    if(found){
        cout << ans.size()+1 << endl;
        for(int i=ans.size()-1; i>=0; i--){
            cout << ans[i] << " ";
        }
        cout << ans[ans.size()-1] << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t, n, k, b[262144], vis[262144];
long long cur, now, sz;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        bool sama = true;
        for(int i=1; i<=n; i++){
            cin >> b[i];
            vis[i] = 0;
            sama = sama && (i == b[i]);
        }
        if(k == 1){
            if(sama){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            bool bisa = true;
            for(int i=1; i<=n && bisa; i++){
                if(vis[i] == 0){
                    cur = i; vis[cur] = 1;
                    while(vis[b[cur]] == 0){
                        cur = b[cur]; vis[cur] = 1;
                    }
                    if(vis[b[cur]] == 1){
                        now = cur; sz = 1;
                        while(b[cur] != now){
                            cur = b[cur]; sz++;
                        }
                        if(sz == k){
                            cur = i; vis[cur] = 2;
                            while(vis[b[cur]] < 2){
                                cur = b[cur]; vis[cur] = 2;
                            }
                        }else{
                            bisa = false;
                        }
                    }else{ //2
                        cur = i; vis[cur] = 2;
                        while(vis[b[cur]] < 2){
                            cur = b[cur]; vis[cur] = 2;
                        }
                    }
                }
            }  
            if(bisa){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}
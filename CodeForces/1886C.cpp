#include<bits/stdc++.h>
using namespace std;
#define pdd pair<double, double>

long long t, n, prv[1048576], nxt[1048576], pos, cur; 
string s, ans = "";

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s >> pos;
        n = s.length(); pos--;
        nxt[0] = 1;
        for(int i=1; i<=n; i++){
            nxt[i] = i+1; prv[i] = i-1;
        }
        prv[n+1] = n;

        cur = 1;
        for(int i=0; pos >= n-i; i++){
            while(nxt[cur]<=n && s[cur-1] <= s[nxt[cur]-1]){
                cur = nxt[cur];
            }
            nxt[prv[cur]] = nxt[cur];
            prv[nxt[cur]] = prv[cur];
            cur = prv[cur];
            if(cur == 0){
                cur = nxt[cur];
            }
            pos -= n-i;
            /*for(int i=nxt[0]; i<=n; i=nxt[i]){
                cout << s[i-1];
            }cout << endl;*/
        }
        //cout << "kelar" << endl;

        cur = nxt[0];
        //cout << "cur " << cur << endl; 
        while(pos--){
            cur = nxt[cur];
            //cout << "cur " << cur << endl; 
        }
        ans += "a";
        ans[ans.length()-1] = s[cur-1];
        //cout << "<" << ans << ">" << endl;
    }
    cout << ans << endl;
}
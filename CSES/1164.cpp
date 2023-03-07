#include <bits/stdc++.h>
using namespace std;

long long n, x, y, curans, ans;
long long room[200069];
queue<long long> q;
pair<long long, pair<long long, long long> > p[400069];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        p[2*i] = {x, {-1, i}};
        p[2*i+1] = {y, {1, i}};
    }
    sort(p, p+(2*n));
    ans = 0; curans = 0;
    for(int i=0; i<2*n; i++){
        curans -= p[i].second.first;
        ans = max(ans, curans);
    }
    cout << ans << endl;
    for(int i=0; i<ans; i++){
        q.push(i+1);
    }
    for(int i=0; i<2*n; i++){
        long long a = p[i].second.first, b = p[i].second.second;
        //cout << a << " " << b << endl;
        if(a<0){
            room[b] = q.front(); q.pop();
        }else{
            q.push(room[b]);
        }
    }
    for(int i=0; i<n; i++){
        cout << room[i] << " ";
    }cout << endl;
}

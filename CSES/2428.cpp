#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069;
long long n, x, a[maxn];
long long sum = 0, ans = 0;
map<long long, long long> m;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int j = 0;
    for(int i=0; i<n; i++){
        while(j < n && !(sum == x && !m[a[j]])){
            if(!m[a[j]]){sum++;}
            m[a[j]]++; j++;
        }
        //cout << i << j << endl;
        ans += (j-i);
        m[a[i]]--;
        if(!m[a[i]]){sum--;}
    }
    cout << ans << endl;
}

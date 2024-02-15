#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

const long long maxn = (1<<22);
long long n, a[maxn], ans[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        ans[maxn-1-a[i]] = a[i];
    }
    for(int i=maxn-1; i>=0; i--){
        for(int j=1; j<maxn; j*=2){
            if(ans[i | j]){
                ans[i] = ans[i | j];
            }
        }
    }
    for(int i=0; i<n; i++){
        if(ans[a[i]]){
            cout << ans[a[i]] << ' ';
        }else{
            cout << "-1 ";
        }
    }cout << endl;
}

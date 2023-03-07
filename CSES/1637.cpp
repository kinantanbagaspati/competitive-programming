#include <bits/stdc++.h>
using namespace std;

long long ans[1000069];

void init(){
    ans[0] = 0;
    for(int i=1; i<1000069; i++){
        ans[i] = -1;
    }
}

long long getans(long long n){
    if(ans[n]>=0){return ans[n];}

    long long m = n, ret=1e18;
    while(m>0){
        if(m%10){ret = min(ret, getans(n - m%10));}
        m/=10;
    }
    ans[n] = ret+1;
    return ret+1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    long long n;
    cin >> n;
    cout << getans(n) << endl;
}

#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int ans[1000069];
int n, x;
int c[100];

void init(){
    ans[0] = 1;
    for(int i=1; i<1000069; i++){ans[i]=-1;}
}

int get_ans(int a){
    if(ans[a] >= 0){
        return ans[a];
    }
    ans[a] = 0;
    for(int i=0; i<n; i++){
        if(a>=c[i]){
            ans[a] = (ans[a] + get_ans(a-c[i]));
            if(ans[a]>=mod){ans[a]-=mod;}
        }
    }
    return ans[a];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> x;
    for(int i=0; i<n; i++){cin >> c[i];}
    init();
    cout << get_ans(x) << endl;
}

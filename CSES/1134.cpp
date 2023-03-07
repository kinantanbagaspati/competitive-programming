#include <bits/stdc++.h>
using namespace std;

long long n, code[200069];
bool last[200069], freq[200069];
set<long long> s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        last[i] = false;
        freq[i+1] = false;
    }
    for(int i=0; i<n-2; i++){
        cin >> code[i];
    }
    code[n-2] = n;
    for(int i=n-2; i>=0; i--){
        if(!freq[code[i]]){
            freq[code[i]] = true;
            last[i] = true;
        }
    }
    for(int i=1; i<=n; i++){
        if(!freq[i]){
            s.insert(i);
        }
    }
    for(int i=0; i<n-1; i++){
        long long a = *(s.begin());
        s.erase(a);
        cout << a << " " << code[i] << endl;
        if(last[i]){
            s.insert(code[i]);
        }
    }
}

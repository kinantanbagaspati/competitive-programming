#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

long long t;
string a, b;
bool c[32][32];

void solve(){
    if(a[0] == b[0]){
        cout << "YES" << endl;
        cout << a[0] << '*' << endl;
        return;
    }
    if(a[a.length()-1] == b[b.length()-1]){
        cout << "YES" << endl;
        cout << '*' << a[a.length()-1] << endl;
        return;
    }

    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            c[i][j] = false;
        }
    }
    for(int i=1; i<a.length(); i++){
        c[a[i-1]-'a'][a[i]-'a'] = true;
    }
    for(int i=1; i<b.length(); i++){
        if(c[b[i-1]-'a'][b[i]-'a']){
            cout << "YES" << endl;
            cout << '*' << b[i-1] << b[i] << '*' << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b;
        solve();
    }
}

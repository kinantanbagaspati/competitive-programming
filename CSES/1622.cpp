#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long cnt=1, occ[26];
    for(int i=0; i<26; i++){
        occ[i] = 0;
    }
    char c[8];
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++){
        c[i] = s[i];
        occ[s[i]-'a']++;
        cnt*=(i+1);
        cnt/=occ[s[i]-'a'];
    }
    cout << cnt << endl;
    sort(c, c+(s.length()));
    for(int i=0; i<cnt; i++){
        for(int j=0; j<s.length(); j++){
            cout << c[j];
        }cout << endl;
        next_permutation(c, c+(s.length()));
    }
}

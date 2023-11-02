#include <bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

string toString(long long x){
    string res = "";
    while(x > 0){
        res += "0";
        res[res.length()-1] += x%10;
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res; 
}
long long freq[16];
string t, n, m;
set<string> s;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    s.insert(n);
    if(n == m){
        cout << 1 << endl; return 0;
    }
    for(int i=2; i<=100; i++){
        for(int j=0; j<10; j++){
            freq[j] = 0;
        }
        for(int j=0; j<n.length(); j++){
            freq[n[j]-'0']++;
        }
        n = "";
        for(int j=0; j<10; j++){
            if(freq[j] > 0){
                n += toString(freq[j]);
                n += "0";
                n[n.length()-1] += j;
            }
        }
        if(n == m){
            cout << i << endl;
            return 0;
        }
        if(s.count(n)){
            cout << "Does not appear" << endl;
            return 0;
        }
        s.insert(n);
    }
    cout << "I'm bored" << endl;
}

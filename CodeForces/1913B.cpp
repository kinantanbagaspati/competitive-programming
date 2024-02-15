#include<bits/stdc++.h>
using namespace std;
#define pll pair<long long, long long>

int t, nb[2], tot[2];
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        tot[0] = 0; tot[1] = 0;
        for(int i=0; i<s.length(); i++){
            tot[s[i]-'0']++;
        }
        nb[0] = tot[0]; nb[1] = tot[1];
        bool udah = false;
        for(int i=0; i<s.length() && !udah; i++){
            if(nb[0] <= tot[1] && nb[1] <= tot[0]){
                cout << i << endl;
                udah = true;
            }
            nb[s[s.length()-1-i] - '0']--;
        }
        if(!udah){
            cout << s.length() << endl;
        }
    } 
}
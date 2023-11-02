#include<bits/stdc++.h>
using namespace std;

long long cur = 0;
string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    for(int i=s.length()-1; i>=0; i--){
        if(s[i] == '0'){
            cur--;
        }else if(cur < 0){
            cur++;
        }else{
            s[i] = '0';
        }
    }
    cout << s << endl;
}
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    long long occ[26];
    for(int i=0; i<26; i++){occ[i]=0;}
    for(int i=0; i<s.length(); i++){
        occ[s[i]-'A']++;
    }
    long long cnt = 0;
    for(int i=0; i<26; i++){
        cnt += occ[i]%2;
    }
    if(cnt>1){
        cout << "NO SOLUTION" << endl;
    }else if(cnt == 1){
        char mid = 'A';
        for(int i=0; i<26; i++){
            if(occ[i]%2){mid+=i;}
            for(int j=0; j<occ[i]/2; j++){
                cout << (char) ('A' + i);
            }
        }cout << mid;
        for(int i=25; i>=0; i--){
            for(int j=0; j<occ[i]/2; j++){
                cout << (char) ('A' + i);
            }
        }cout << endl;
    }else{
        for(int i=0; i<26; i++){
            for(int j=0; j<occ[i]/2; j++){
                cout << (char) ('A' + i);
            }
        }
        for(int i=25; i>=0; i--){
            for(int j=0; j<occ[i]/2; j++){
                cout << (char) ('A' + i);
            }
        }cout << endl;
    }
}

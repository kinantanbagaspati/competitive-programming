#include <bits/stdc++.h>
using namespace std;

bool border[1000069];

void init(long long n){
    for(int i=1; i<=n; i++){
        border[i] = false;
    }
}

void occ(string pat){
    int lps[pat.length()];
    lps[0] = 0;
    int i=1, j=0;
    while(i<pat.length()){
        if(pat[i] == pat[j]){
            j++;
            lps[i] = j;
            i++;
        }else if(j==0){
            lps[i] = 0;
            i++;
        }else{
            j = lps[j-1];
        }
    }
    i = lps[i-1];
    while(i>0){
        border[i] = true;
        i = lps[i-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string pat;
    cin >> pat;
    long long n =pat.length();
    init(n);
    occ(pat);
    for(int i=1; i<n; i++){
        bool found = true;
        for(int j=1; i*j<n; j++){
            found = found && border[n-i*j];
        }
        if(found){cout << i << " ";}
    }
    cout << n << endl;
}

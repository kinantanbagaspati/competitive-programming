#include <bits/stdc++.h>
using namespace std;

long long occ(string pat, string txt){
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
    i=0; j=0;
    long long ret = 0;
    while(i<txt.length()){
        if(txt[i] == pat[j]){
            j++;
            i++;
        }else if(j==0){
            i++;
        }else if(j==pat.length()){
            ret++;
            j=lps[j-1];
        }else{
            j = lps[j-1];
        }
    }
    if(j==pat.length()){ret++;}
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string pat, txt;
    cin >> txt;
    cin >> pat;
    cout << occ(pat, txt);
}

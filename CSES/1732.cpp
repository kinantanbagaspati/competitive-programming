#include <bits/stdc++.h>
using namespace std;

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
    vector<long long> ans;
    i = lps[i-1];
    while(i>0){
        ans.push_back(i);
        i = lps[i-1];
    }
    for(i=ans.size()-1; i>=0; i--){
        cout << ans[i] << " ";
    }cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string pat;
    cin >> pat;
    occ(pat);
}

#include <bits/stdc++.h>
using namespace std;

vector<string> gc[16];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    gc[0].push_back("0");
    gc[0].push_back("1");
    for(int i=1; i<n; i++){
        for(int j=0; j<gc[i-1].size(); j++){
            gc[i].push_back("0"+gc[i-1][j]);
        }
        for(int j=gc[i-1].size()-1; j>=0; j--){
            gc[i].push_back("1"+gc[i-1][j]);
        }
    }
    for(int i=0; i<gc[n-1].size(); i++){
        cout << gc[n-1][i] << endl;
    }
}

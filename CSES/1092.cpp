#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    if(n%4 == 0){
        cout << "YES" << endl;
        cout << n/2 << endl;
        for(int i=0; i<n; i++){
            if(i%4 == 0 || i%4 == 3){
                cout << i+1 << " ";
            }
        }cout << endl;
        cout << n/2 << endl;
        for(int i=0; i<n; i++){
            if(i%4 == 1 || i%4 == 2){
                cout << i+1 << " ";
            }
        }cout << endl;
    }else if(n%4 == 3){
        cout << "YES" << endl;
        cout << n/2 << endl;
        for(int i=0; i<n; i++){
            if(i%4 == 2 || i%4 == 3){
                cout << i+1 << " ";
            }
        }cout << endl;
        cout << (n+1)/2 << endl;
        for(int i=0; i<n; i++){
            if(i%4 == 0 || i%4 == 1){
                cout << i+1 << " ";
            }
        }cout << endl;
    }else{
        cout << "NO" << endl;
    }
}

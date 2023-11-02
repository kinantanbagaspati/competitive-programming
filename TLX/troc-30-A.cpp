#include<bits/stdc++.h>
using namespace std;

int n, x, y;

int main(){
    cin >> n >> x >> y;
    if(x > y){
        cout << n/y * x + n%y << endl;
    }else{
        cout << n << endl;
    }
}
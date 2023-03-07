#include <bits/stdc++.h>
using namespace std;

void hanoi(long long n, long long aw, long long ak){
    if(n>0){
        if(1!=aw && 1!=ak){
            hanoi(n-1, aw, 1);
            cout << aw << " " << ak<< endl;
            hanoi(n-1, 1, ak);
        }else if(2!=aw && 2!= ak){
            hanoi(n-1, aw, 2);
            cout << aw << " " << ak<< endl;
            hanoi(n-1, 2, ak);
        }else{
            hanoi(n-1, aw, 3);
            cout << aw << " " << ak<< endl;
            hanoi(n-1, 3, ak);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;
    cout << (1<<n)-1 << endl;
    hanoi(n, 1, 3);
}

#include<bits/stdc++.h>
using namespace std;

long long nn, pp, hh;

string getAns(long long n, long long p, long long h){
    if(n == 1){
        if(p == h){
            return "R";
        }else{
            return "L";
        }
    }
    //Nyoba L
    long long nextsz = (1LL << (n-1));
    long long nextp = p - nextsz;
    if(nextp < 0){
        nextp = - 1 - nextp;
    }
    string moves = getAns(n-1, nextp, h/2);
    //cout << "NPH " << n << " " << p << " " << h << endl;
    bool plus1 = (p < nextsz);
    //cout  << plus1 << " " << nextp << " " << nextsz << endl;
    for(long long i=0; i<n-1; i++){
        if(nextp < nextsz/2){
            if(moves[i] == 'L'){
                plus1 = !plus1;
                nextp = nextsz/2 - 1 - nextp;
            }
        }else{
            if(moves[i] == 'L'){
                nextp -= nextsz/2;
            }else{
                plus1 = !plus1;
                nextp = nextsz - 1 - nextp;
            }
        }
        nextsz /= 2;
        //cout << plus1 << " " << nextp << " " << nextsz << endl;
    }
    if(plus1 == (h%2)){
        return "L" + moves;
    }else{
        for(long long i=0; i<n-1; i++){
            if(moves[i] == 'L'){
                moves[i] = 'R';
            }else{
                moves[i] = 'L';
            }
        }
        return "R" + moves;
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> nn >> pp >> hh;
    cout << getAns(nn, pp-1, hh-1) << endl;
}
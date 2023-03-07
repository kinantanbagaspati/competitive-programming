#include <bits/stdc++.h>
using namespace std;


int before[30] = {
    1, 2, 4, 8, 16,
    23, 46, 29, 58, 116,
    223, 446, 289, 578, 1156,
    1223, 2446, 2489, 4789, 5789,
    11578, 12356, 12247, 24449, 48889,
    77789, 155578, 111356, 122227, 244445
};
int after[6] = {48889, 77789, 155578, 111356, 122227, 244445};

/*
void nxt(){
    len = s[0].length();
    s[1] = "";
    carry = 0;
    for(int i=0; i<len; i++){
        //cout << s[0][len-1-i] << " ";
        sum = (s[0][len-1-i] - '0')*2 + carry;
        //cout << sum << endl;
        s[1] += "0";
        s[1][i] += sum % 10;
        carry = sum / 10;
    }
    if(carry){
        s[1] += "1"; len++;
    }
    sort(s[1].begin(), s[1].end());
    s[0] = s[1];
}
*/

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int i;
    cin >> i; i--;
    if(i < 30){
        cout << before[i] << endl;
    }else{
        cout << after[i%6] << endl;
    }
}

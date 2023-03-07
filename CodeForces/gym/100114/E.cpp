#include <bits/stdc++.h>
using namespace std;

int freqin[10], freq[10], top, bot;
void addFreq(int toAdd){
    for(int i=0; i<4; i++){
        freq[toAdd%10]++;
        toAdd /= 10;
    }
}
void reset(){
    for(int i=0; i<10; i++){
        freq[i] = 0;
    }
}
bool check(){
    bool toReturn = true;
    for(int i=0; i<10; i++){
        toReturn = toReturn && (freq[i] == freqin[i]);
    }
    return toReturn;
}
void print(){
    for(int i=0; i<10; i++){
        cout << freq[i] << " ";
    }cout << endl;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int sum = 0;
    for(int i=0; i<10; i++){
        cin >> freqin[i];
        sum += freqin[i];
    }
    freqin[0] += 31-sum;
    int maxk = 9, maxbot = 10000;
    for(int top=0; top < 10000; top++){
        if(top*maxk >= 10000){
            maxk--;
            maxbot = (maxk+1)*(maxk+1)*(maxk+1)*(maxk+1);
        }
        //cout << maxk << endl;
        int bot = 0;
        for(int bot=0; bot < maxbot; bot++){
            reset();
            addFreq(top);
            int j = bot;
            for(int k=0; k<4; k++){
                addFreq(j%(maxk+1) * top);
                j /= (maxk+1);
            }
            addFreq(bot);
            int res = top*bot;
            if(res < 10000000){
                for(int i=0; i<7; i++){
                    freq[res%10]++;
                    res /= 10;
                }
            }

            if(check()){
                cout << top << endl;
                cout << bot << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl << -1 << endl;
}

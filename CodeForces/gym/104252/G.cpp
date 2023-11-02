#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

const double pi = acos(-1);
int m1, m2, x, y, maxidx, minidx, idx1, idx2;
vector<pii> p1[3], p2[3];
vector<pii> locus0, locus1, locus2;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> m1;
    maxidx = 0;
    minidx = 0;
    for(int i=0; i<m1; i++){
        cin >> x >> y; x*=2; y*=2;
        p1[0].push_back({x, y});
        if(y > p1[0][maxidx].second){
            maxidx = i;
        }
        if(y < p1[0][minidx].second){
            minidx = i;
        }
    }
    for(int i=0; i<m1; i++){
        p1[1].push_back(p1[0][(minidx+i)%m1]);
        p1[2].push_back(p1[0][(maxidx+i)%m1]);
    }

    cin >> m2;
    maxidx = 0;
    minidx = 0;
    for(int i=0; i<m2; i++){
        cin >> x >> y; x*=2; y*=2;
        p2[0].push_back({x, y});
        if(y > p2[0][maxidx].second){
            maxidx = i;
        }
        if(y < p2[0][minidx].second){
            minidx = i;
        }
    }
    for(int i=0; i<m1; i++){
        p2[1].push_back(p2[0][(minidx+i)%m1]);
        p2[2].push_back(p2[0][(maxidx+i)%m1]);
    }

    idx1 = 0; idx2 = 0;
    locus0.push_back({(p1[1][0].first + p2[1][0].first)/2, (p1[1][0].second + p2[1][0].second)/2});
    while(idx1 < m1 && idx2 < m2){
        if(
            atan2(p1[1][idx1+1].second - p1[1][idx1].second, p1[1][idx1+1].first - p1[1][idx1].first)
            < atan2(p1[1][idx1+1].second - p1[1][idx1].second, p1[1][idx1+1].first - p1[1][idx1].first)
        ){

        }
    }
    while(idx1 < m1){

    }
    while(idx2 < m2){

    }
}
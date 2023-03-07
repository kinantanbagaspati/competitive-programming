#include <bits/stdc++.h>
using namespace std;

const long long maxn = 200069;
long long n, info[maxn][3];
pair<long long, long long> sorter[maxn];
multiset<pair<long long, long long> > ms;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> info[i][0] >> info[i][1] >> info[i][2];
        sorter[i] = {info[i][1], i};
    }
    sort(sorter, sorter+n);

    long long current = 0;
    ms.insert({0,0});
    for(int i=0; i<n; i++){
        long long id = sorter[i].second;
        long long com = ms.lower_bound({-info[id][0]+1, 0})->second;
        ms.erase({-info[id][1], current});
        current = max(com + info[id][2], current);
        ms.insert({-info[id][1], current});
    }
    cout << current << endl;
}

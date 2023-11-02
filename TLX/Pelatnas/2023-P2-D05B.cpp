#include <bits/stdc++.h>
using namespace std;

const long long maxm = 262144;
long long n, m, q, curtime=0, s;
long long lr[maxm][2], ud[maxm][2], dif[maxm], ans[maxm];
pair<long long, long long> startTime[maxm], endTime[maxm], queries[maxm];
long long startIdx=0, endIdx=0, totSum=0;
set<long long> pos, neg;
map<long long, long long> dis, disCumulative;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    for(int i=0; i<m; i++){
        cin >> lr[i][0] >> lr[i][1];
        ud[i][0] = lr[i][0]; ud[i][1] = lr[i][0];
        dif[i] = curtime - lr[i][0];
        curtime += lr[i][1] - lr[i][0] + 1;
        startTime[i] = {lr[i][0], i};
        endTime[i] = {lr[i][1], i};
    }
    sort(startTime, startTime + m);
    sort(endTime, endTime + m);

    for(int i=1; i<=n; i++){
        //cout << "i = " << i << endl; 
        while(startIdx < m && startTime[startIdx].first == i){ // masukin range baru
            long long idx = startTime[startIdx].second;
            set<long long>::iterator up = pos.lower_bound(idx+1), down = neg.lower_bound(-idx+1);
            if((up != pos.end()) && (down != neg.end())){ // yg baru ada diantara sebuah pair
                //cout << "masuk " << -(*down) << " < " << idx << " < " << (*up) << " += " << i - ud[*up][1] << endl;
                dis[dif[*up] - dif[-(*down)] - 1] += i - ud[*up][1];
                totSum += i - ud[*up][1];
            }
            if(up != pos.end()){
                ud[*up][1] = i;             
            }
            if(down != neg.end()){
                ud[-(*down)][0] = i;
            }
            pos.insert(idx); 
            neg.insert(-idx);
            startIdx++;
        }
        while(endIdx < m && endTime[endIdx].first == i){ // hapus range
            long long idx = endTime[endIdx].second;
            set<long long>::iterator up = pos.lower_bound(idx+1), down = neg.lower_bound(-idx+1);
            if(up != pos.end()){
                //cout << "keluar " << idx << " < " << (*up) << " += " <<  i - ud[i][0] + 1 << endl;
                dis[dif[*up] - dif[idx] - 1] += i - ud[idx][0] + 1;
                totSum += i - ud[idx][0] + 1;
                ud[*up][1] = i+1;
            }
            if(down != neg.end()){
                //cout << "keluar " << -(*down) << " < " << idx << " += " <<  i - ud[i][1] + 1 << endl;
                dis[dif[idx] - dif[-(*down)] - 1] += i - ud[idx][1] + 1;
                totSum += i - ud[idx][1] + 1;
                ud[-(*down)][0] = i+1;
            }
            pos.erase(idx);
            neg.erase(-idx);
            endIdx++;
        } 
        //cout << i << ": " << startIdx << " " << endIdx << endl;
    }

    for(int i=0; i<q; i++){
        cin >> s; queries[i] = {s, i};
    }
    sort(queries, queries+q);
    map<long long, long long>::iterator itr = dis.begin();
    //cout << totSum << endl;
    for(int i=0; i<q; i++){
        while((itr != dis.end()) && ((itr->first) < queries[i].first)){
            //cout << (itr->first) << " < " << queries[i].first << " jadi ";
            totSum -= (itr->second); itr++;
            //cout << totSum << " " << endl;
        }
        ans[queries[i].second] = totSum;
    }
    for(int i=0; i<q; i++){
        cout << ans[i] << " ";
    }cout << endl;

    return 0;
}
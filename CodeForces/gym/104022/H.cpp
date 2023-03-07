#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int n, nbtitik[8];
double xyz[8][16][3], cpy[8][16][3];

void init(){
    nbtitik[1] = 2;
    xyz[1][0][0] = 0; xyz[1][0][1] = 0; xyz[1][0][2] = 0;
    xyz[1][1][0] = 1; xyz[1][1][1] = 0; xyz[1][1][2] = 0;

    nbtitik[2] = 3;
    xyz[2][0][0] = 0.000000000; xyz[2][0][1] = 0.000000000; xyz[2][0][2] = 0.000000000;
    xyz[2][1][0] = 1.000000000; xyz[2][1][1] = 0.000000000; xyz[2][1][2] = 0.000000000;
    xyz[2][2][0] = 0.500000000; xyz[2][2][1] = 0.866025404; xyz[2][2][2] = 0.000000000;

    nbtitik[3] = 4;
    xyz[3][0][0] = 0.500000000; xyz[3][0][1] = 0.000000000; xyz[3][0][2] = -0.353553391;
    xyz[3][1][0] = -0.500000000; xyz[3][1][1] = 0.000000000; xyz[3][1][2] = -0.353553391;
    xyz[3][2][0] = 0.000000000; xyz[3][2][1] = 0.500000000; xyz[3][2][2] = 0.353553391;
    xyz[3][3][0] = 0.000000000; xyz[3][3][1] = -0.500000000; xyz[3][3][2] = 0.353553391;

    nbtitik[4] = 6;
    xyz[4][0][0] = 0.707106781; xyz[4][0][1] = 0.000000000; xyz[4][0][2] = 0.000000000;
    xyz[4][1][0] = -0.707106781; xyz[4][1][1] = 0.000000000; xyz[4][1][2] = 0.000000000;
    xyz[4][2][0] = 0.000000000; xyz[4][2][1] = 0.707106781; xyz[4][2][2] = 0.000000000;
    xyz[4][3][0] = 0.000000000; xyz[4][3][1] = -0.707106781; xyz[4][3][2] = 0.000000000;
    xyz[4][4][0] = 0.000000000; xyz[4][4][1] = 0.000000000; xyz[4][4][2] = 0.707106781;
    xyz[4][5][0] = 0.000000000; xyz[4][5][1] = 0.000000000; xyz[4][5][2] = -0.707106781;

    nbtitik[5] = 12;
    xyz[5][0][0] = 0.000000000; xyz[5][0][1] = 0.500000000; xyz[5][0][2] = 0.809016994;
    xyz[5][1][0] = 0.000000000; xyz[5][1][1] = -0.500000000; xyz[5][1][2] = 0.809016994;
    xyz[5][2][0] = 0.000000000; xyz[5][2][1] = 0.500000000; xyz[5][2][2] = -0.809016994;
    xyz[5][3][0] = 0.000000000; xyz[5][3][1] = -0.500000000; xyz[5][3][2] = -0.809016994;
    xyz[5][4][0] = 0.500000000; xyz[5][4][1] = 0.809016994; xyz[5][4][2] = 0.000000000;
    xyz[5][5][0] = 0.500000000; xyz[5][5][1] = -0.809016994; xyz[5][5][2] = 0.000000000;
    xyz[5][6][0] = -0.500000000; xyz[5][6][1] = 0.809016994; xyz[5][6][2] = 0.000000000;
    xyz[5][7][0] = -0.500000000; xyz[5][7][1] = -0.809016994; xyz[5][7][2] = 0.000000000;
    xyz[5][8][0] = 0.809016994; xyz[5][8][1] = 0.000000000; xyz[5][8][2] = 0.500000000;
    xyz[5][9][0] = 0.809016994; xyz[5][9][1] = 0.000000000; xyz[5][9][2] = -0.500000000;
    xyz[5][10][0] = -0.809016994; xyz[5][10][1] = 0.000000000; xyz[5][10][2] = 0.500000000;
    xyz[5][11][0] = -0.809016994; xyz[5][11][1] = 0.000000000; xyz[5][11][2] = -0.500000000;

    for(int i=1; i<=5; i++){
        for(int j=0; j<nbtitik[i]; j++){
            for(int k=0; k<3; k++){
                cpy[i][j][k] = xyz[i][j][k];
            }
        }
    }
}

void rot(int idx, int axis, double teta){
    for(int i=0; i<nbtitik[idx]; i++){
        double mag = sqrt(xyz[idx][i][(axis+1)%3]*xyz[idx][i][(axis+1)%3] + xyz[idx][i][(axis+2)%3]*xyz[idx][i][(axis+2)%3]);
        double arg = atan2(xyz[idx][i][(axis+1)%3], xyz[idx][i][(axis+2)%3]);

        xyz[idx][i][(axis+1)%3] = mag * sin(arg + teta);
        xyz[idx][i][(axis+2)%3] = mag * cos(arg + teta);
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    srand((unsigned)time(NULL));

    //cout << (double)(rand() % 100) << endl;
    cin >> n;
    if(n == 10){
        for(int i=0; i<3; i++){
            rot(3, i, rand() % 100);
            rot(4, i, rand() % 100);
        }
        cout << 4*4*6 << endl;
        for(int i=0; i<nbtitik[3]; i++){
            for(int j=0; j<nbtitik[4]; j++){
                for(int k=0; k<nbtitik[3]; k++){
                    for(int m=0; m<3; m++){
                        cout << fixed << setprecision(9) << xyz[3][i][m] + xyz[4][j][m] + cpy[3][k][m];
                        if(m<2){
                            cout << " ";
                        }
                    }cout << endl;
                }
            }
        }
    }else if(n > 5){
        for(int i=0; i<3; i++){
            rot(n-5, i, rand() % 100);
        }
        cout << nbtitik[n-5] * nbtitik[5] << endl;
        for(int i=0; i<nbtitik[5]; i++){
            for(int j=0; j<nbtitik[n-5]; j++){
                for(int k=0; k<3; k++){
                    cout << fixed << setprecision(9) << xyz[n-5][j][k] + cpy[5][i][k];
                    if(k<2){
                        cout << " ";
                    }
                }cout << endl;
            }
        }
    }else{
        cout << nbtitik[n] << endl;
        for(int i=0; i<nbtitik[n]; i++){
            for(int j=0; j<3; j++){
                cout << fixed << setprecision(9) << xyz[n][i][j];
                if(j<2){
                    cout << " ";
                }
            }cout << endl;
        }
    }
}

#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, Q, askCount;
    vector<int> warna, u, v;
    vector<vector<int> > 

    void InputFormat() {
        LINE(N);
        LINE(warna % SIZE(N));
        LINES(warna % SIZE(N))
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(5);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(2 <= N && N <= 500000 && (N%2==0));
        CONS(1 <= M && M <= 1e9);
        CONS(2 <= K && K <= 1e9);
    }

    void Subtask1() {
        Points(4);

        CONS(N <= 30);
        CONS(M <= 3);
    }

    void Subtask2() {
        Points(16);

        CONS(N <= 5000);
    }

    void Subtask3() {
        Points(80);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Subtasks({1, 2, 3});
        Input({
            "4 2 10"
        });
        Output({
            "6"
        });
    }

    void TestGroup1(){
        Subtasks({1, 2, 3});
        for(int i=0; i<6; i++){
            CASE(N = rnd.nextInt(1,15)*2, M=(i/2+1), K = rnd.nextInt(2, 1e9))
        }
    }
    void TestGroup2(){
        Subtasks({2, 3});
        for(int i=0; i<6; i++){
            CASE(N = rnd.nextInt(1, 50)*2, M = rnd.nextInt(1, 1e9), K = rnd.nextInt(2, 1e9));
        }
        for(int i=0; i<6; i++){
            CASE(N = rnd.nextInt(1, 2500)*2, M = rnd.nextInt(1, 1e9), K = rnd.nextInt(2, 1e9));
        }
    }
    void TestGroup3(){
        Subtasks({3});
        for(int i=0; i<20; i++){
            CASE(N = rnd.nextInt(1, 250000)*2, M = rnd.nextInt(1, 1e9), K = rnd.nextInt(2, 1e9));
        }
    }
};
#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;
using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMIN = 1;
    const int NMAX = 1e5;
    const int LENMIN = 1;
    const int LENMAX = 100;
    const int AMIN = 0;
    const int AMAX = 1e9;

    int N;
    vector<string> S;
    vector<int> A;
    int ansN;
    vector<string> ansS;
    vector<long long> ansA;

    void InputFormat() {
        LINE(N);
        LINES(S, A) % SIZE(N);
    }

    void OutputFormat() {
        LINE(ansN);
        LINES(ansS, ansA) % SIZE(ansN);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(NMIN <= N && N <= NMAX);
        CONS(valid_array(N, S, A));
    }

private:
    bool valid_array(int sz, const vector<string>& vecS, const vector<int>& vecA){
        if (sz != vecA.size()) return 0;
        if (sz != vecS.size()) return 0;
        for (auto x : vecA){
            if (x < AMIN || x > AMAX) return 0;
        }
        for (auto x : vecS){
            if (x.size() < LENMIN || x.size() > LENMAX) return 0;
        }
        return 1;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5",
            "doraemon 99",
            "nobita 0",
            "doraemon 10",
            "nobita 5",
            "shizuka 100"
        });
        Output({
            "3",
            "doraemon 109",
            "nobita 5",
            "shizuka 100"
        });
    }
    void BeforeTestCase() {
        S.clear();
        A.clear();
    }

    void TestCases() {
        CASE(N = 1, make_random_query(N, S, A, 1));
        CASE(N = 27, make_random_query(N, S, A, 1));
        CASE(N = 300, make_random_query(N, S, A, 2));
        for (int i=0;i<5;i++){
            CASE(N = rnd.nextInt(6, NMAX), make_random_query(N, S, A, LENMAX));
        }
        for (int i=0;i<10;i++){
            CASE(N = NMAX, make_random_query(N, S, A, 3));
        }
    }

private:
    void make_random_query(int n, vector<string>& S, vector<int>& A, int maxLen){
        string alph = "abcdefghijklmnopqrstuvwxyz";
        for (int i=0;i<n;i++){
            string s = "";
            int x = rnd.nextInt(AMIN, AMAX);
            A.push_back(x);
            int tmp = rnd.nextInt(LENMIN, maxLen);
            while (tmp--) {
                int y = rnd.nextInt(0, 25);
                s += alph[y];
            }
            S.push_back(s);
        }
    }
};
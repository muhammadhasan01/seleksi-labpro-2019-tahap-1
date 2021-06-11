#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e3;
    const int KMAX = 1e3;
    const int PMAX = 1e9;
    const int WMAX = 1e3;

    int N, K;
    vector<int> P, W;
    long long ans;

    void InputFormat() {
        LINE(N, K);
        LINES(P, W) % SIZE(N);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMAX);
        CONS(1 <= K && K <= KMAX);
        CONS(CheckConstraint(P, 1, PMAX));
        CONS(CheckConstraint(W, 1, WMAX));
    }

private:
    bool CheckConstraint(vector<int>& v, int low, int high) {
        for (int x : v) {
            if (x < low || x > high) {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5 10",
            "2 3",
            "10 6",
            "8 4",
            "3 2",
            "6 2"
        });
        Output({
            "19",
        });
    }
    void BeforeTestCase() {
        P.clear();
        W.clear();
    }

    void TestCases() {
        for (int i = 0; i < 5; i++) {
            CASE(N = rnd.nextInt(1, 100), K = rnd.nextInt(1, 500), generateTestCases(N, P, 1, 1000, W, 1, (K + 1) / 2));
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = rnd.nextInt(100, 500), K = rnd.nextInt(500, 1000), generateTestCases(N, P, 1, PMAX, W, 1, K));
        }
        for (int i = 0; i < 15; i++) {
            CASE(N = 1000, K = rnd.nextInt(1, KMAX), generateTestCases(N, P, 1, PMAX, W, 1, K));
        }
        for (int i = 0; i < 5; i++) {
            CASE(N = 1000, K = rnd.nextInt(KMAX / 2, KMAX), generateTestCases(N, P, PMAX / 2, PMAX, W, 1, K));
        }
    }

private:
    void generateTestCases(int N, vector<int>& P, int lp, int hp, vector<int>& W, int lw, int hw) {
        P.resize(N);
        W.resize(N);
        for (int i = 0; i < N; i++) {
            P[i] = rnd.nextInt(lp, hp);
            W[i] = rnd.nextInt(lw, hw);
        }
    }
};
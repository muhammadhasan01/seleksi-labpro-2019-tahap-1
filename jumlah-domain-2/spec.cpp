#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;
using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int AMAX = 1e9;

    int N, Q;
    vector<int> L, R;
    vector<int> A;
    vector<int> ans;

    void InputFormat() {
        LINE(N);
        LINES(L, R) % SIZE(N);
        LINE(Q);
        LINES(A) % SIZE(Q);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(Q);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMAX);
        CONS(1 <= Q && Q <= NMAX);
        CONS(valid_pos(N, L));
        CONS(valid_pos(N, R));
        CONS(valid_pos(Q, A));
    }

private:
    bool valid_pos(int sz, const vector<int>& vec){
        if (sz != vec.size()) return 0;
        for (auto x : vec){
            if (x < 1 || x > AMAX) return 0;
        }
        return 1;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "2",
            "1 10",
            "6 20",
            "3",
            "2",
            "7",
            "19",
        });
        Output({
            "1",
            "2",
            "1"
        });
    }
    void BeforeTestCase() {
        L.clear();
        R.clear();
        A.clear();
        ans.clear();
    }

    void TestCases() {
        for (int i=0;i<3;i++){
            CASE(N = 1, Q = rnd.nextInt(1, NMAX), make_random_query(N, Q, L, R, A));
        }
        for (int i=0;i<5;i++){
            CASE(N = rnd.nextInt(1, NMAX), Q = rnd.nextInt(1, NMAX), make_random_query(N, Q, L, R, A));
        }
        for (int i=0;i<10;i++){
            CASE(N = NMAX, Q = NMAX, make_random_query(N, Q, L, R, A));
        }
    }

private:
    void make_random_query(int n, int q, vector<int>& L, vector<int>& R, vector<int>& A){
        for (int i=0;i<n;i++){
            int a = rnd.nextInt(1, AMAX);
            int b = rnd.nextInt(1, AMAX);
            if (a > b) swap(a, b);
            L.push_back(a);
            R.push_back(b);
        }
        for (int i=0;i<q;i++){
            A.push_back(rnd.nextInt(1, AMAX));
        }
    }
};
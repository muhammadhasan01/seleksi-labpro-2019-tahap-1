#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;
using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e4;
    const int QMAX = 1e2;
    const int AMAX = 1e9;

    int N, Q;
    vector<int> A;
    vector<int> L, R;
    vector<int> ans;

    void InputFormat() {
        LINE(N);
        LINE(A % SIZE(N));
        LINE(Q);
        LINES(L, R) % SIZE(Q);
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
        CONS(1 <= Q && Q <= QMAX);
        CONS(valid_pos(N, A, AMAX));
        CONS(valid_pos(Q, L, N));
        CONS(valid_pos(Q, R, N));
    }

private:
    bool valid_pos(int sz, const vector<int>& vec, int mx){
        if (sz != vec.size()) return 0;
        for (auto x : vec){
            if (x < 1 || x > mx) return 0;
        }
        return 1;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5",
            "1 4 3 2 9",
            "3",
            "1 3",
            "2 4",
            "4 5"
        });
        Output({
            "3",
            "3",
            "2"
        });
    }
    void BeforeTestCase() {
        A.clear();
        L.clear();
        R.clear();
        ans.clear();
    }

    void TestCases() {
        for (int i=0;i<3;i++){
            CASE(N = 1, Q = rnd.nextInt(1, QMAX), make_random_query(N, Q, L, R, A));
        }
        for (int i=0;i<5;i++){
            CASE(N = rnd.nextInt(1, NMAX), Q = rnd.nextInt(1, QMAX), make_random_query(N, Q, L, R, A));
        }
        for (int i=0;i<10;i++){
            CASE(N = NMAX, Q = QMAX, make_random_query(N, Q, L, R, A));
        }
        for (int i=0;i<10;i++){
            CASE(N = NMAX, Q = QMAX, random_corner(N, Q, L, R, A));
        }
    }

private:
    void make_random_query(int n, int q, vector<int>& L, vector<int>& R, vector<int>& A){
        for (int i=0;i<n;i++){
            A.push_back(rnd.nextInt(1, AMAX));
        }
        for (int i=0;i<q;i++){
            int a = rnd.nextInt(1, N);
            int b = rnd.nextInt(1, N);
            if (a > b) swap(a, b);
            L.push_back(a);
            R.push_back(b);
        }
    }
    void random_corner(int n, int q, vector<int>& L, vector<int>& R, vector<int>& A){
        for (int i=0;i<n;i++){
            A.push_back(rnd.nextInt(1, AMAX));
        }
        for (int i=0;i<q;i++){
            int a = rnd.nextInt(1, 500);
            int b = rnd.nextInt(N - 500 + 1, N);
            if (a > b) swap(a, b);
            L.push_back(a);
            R.push_back(b);
        }
    }
};
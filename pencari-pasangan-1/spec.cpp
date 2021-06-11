#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;
using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMIN = 2;
    const int NMAX = 1e2;
    const int AMIN = 1;
    const int AMAX = 1e9;

    int N, L, R;
    vector<int> A;
    int ans;

    void InputFormat() {
        LINE(N, L, R);
        LINE(A);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints() {
        CONS(NMIN <= N && N <= NMAX);
        CONS(AMIN <= L && L <= AMAX);
        CONS(AMIN <= R && R <= AMAX);
        CONS(valid_array(N, A));
    }

private:
    bool valid_array(int sz, const vector<int>& vec){
        if (sz != vec.size()) return 0;
        for (auto x : vec){
            if (x < AMIN || x > AMAX) return 0;
        }
        return 1;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5 4 7",
            "4 2 5 1 3"
        });
        Output({
            "7"
        });
    }
    void BeforeTestCase() {
        A.clear();
    }

    void TestCases() {
        CASE(N = 2, make_random_query(N, A));
        CASE(N = 3, make_random_query(N, A));
        CASE(N = 5, make_random_query(N, A));
        for (int i=0;i<5;i++){
            CASE(N = rnd.nextInt(6, NMAX), make_random_query(N, A));
        }
        for (int i=0;i<10;i++){
            CASE(N = NMAX, make_random_query(N, A));
        }
    }

private:
    void make_random_query(int n, vector<int>& A){
        int minx = 1e9, maxx = 0;
        for (int i=0;i<n;i++){
            int x = rnd.nextInt(AMIN, AMAX);
            minx = min(minx, x);
            maxx = max(maxx, x);
            A.push_back(x);
        }
        L = rnd.nextInt(minx, maxx);
        R = rnd.nextInt(minx, maxx);
        if (L > R) swap(L, R);
    }
};
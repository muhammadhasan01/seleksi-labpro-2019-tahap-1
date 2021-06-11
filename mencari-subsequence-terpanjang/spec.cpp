#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;
using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMIN = 1;
    const int NMAX = 1e3;
    const int AMIN = 1;
    const int AMAX = 1e5;

    int N;
    vector<int> X, Y, Z;
    int ans;

    void InputFormat() {
        LINE(N);
        LINES(X, Y, Z) % SIZE(N);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(NMIN <= N && N <= NMAX);
        CONS(valid_array(N, X, Y, Z));
    }

private:
    bool valid_array(int sz, const vector<int>& vecX, const vector<int>& vecY, const vector<int>& vecZ){
        if (sz != vecX.size()) return 0;
        if (sz != vecY.size()) return 0;
        if (sz != vecZ.size()) return 0;
        for (auto x : vecX){
            if (x < AMIN || x > AMAX) return 0;
        }
        for (auto x : vecY){
            if (x < AMIN || x > AMAX) return 0;
        }
        for (auto x : vecZ){
            if (x < AMIN || x > AMAX) return 0;
        }
        return 1;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5",
            "4 5 2",
            "1 5 7",
            "2 6 8",
            "5 6 3",
            "6 7 4"
        });
        Output({
            "3"
        });
    }
    void BeforeTestCase() {
        X.clear();
        Y.clear();
        Z.clear();
    }

    void TestCases() {
        CASE(N = 1, make_random_query(N, X, Y, Z));
        CASE(N = 27, make_random_query(N, X, Y, Z));
        CASE(N = 300, make_random_query(N, X, Y, Z));
        for (int i=0;i<5;i++){
            CASE(N = rnd.nextInt(6, NMAX), make_random_query(N, X, Y, Z));
        }
        for (int i=0;i<10;i++){
            CASE(N = NMAX, make_random_query_better(N, X, Y, Z));
        }
    }

private:
    void make_random_query(int n, vector<int>& X, vector<int>& Y, vector<int>& Z){
        for (int i=0;i<n;i++){
            int x = rnd.nextInt(AMIN, AMAX);
            X.push_back(x);
            int y = rnd.nextInt(AMIN, AMAX);
            Y.push_back(y);
            int z = rnd.nextInt(AMIN, AMAX);
            Z.push_back(z);
        }
    }

    void make_random_query_better(int n, vector<int>& X, vector<int>& Y, vector<int>& Z){
        for (int i=0;i<n;i++){
            int x = rnd.nextInt(AMAX / n * i, min(AMAX, AMAX / n * (i + 1) - 1));
            int y = rnd.nextInt(AMAX / n * i, min(AMAX, AMAX / n * (i + 1) - 1));
            int z = rnd.nextInt(AMIN, min(AMAX, AMAX / n * (i + 1) - 1));
            if (x < AMIN) x = AMIN;
            if (y < AMIN) y = AMIN;
            if (z < AMIN) z = AMIN;
            X.push_back(x);
            Y.push_back(y);
            Z.push_back(z);
        }
    }
};
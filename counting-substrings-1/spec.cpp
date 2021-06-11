#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int SMAX = 1e2;
    const int QMAX = 1e2;
    const int PMAX = 1e2;

    string S;
    int Q;
    vector<string> P;
    vector<int> ans;

    void InputFormat() {
        LINE(S);
        LINE(Q);
        LINES(P) % SIZE(Q);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(Q);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(CheckString(S, 1, SMAX));
        CONS(1 <= Q && Q <= QMAX);
        CONS(CheckConstraint(P, S, 1, PMAX));
    }

private:
    bool CheckString(string& str, int low, int high) {
        int len = str.size();
        if (len < low || len > high) {
            return false;
        }
        for (char cc : str) {
            if (!isalpha(cc)) {
                return false;
            }
            if (!islower(cc)) {
                return false;
            }
        }
        return true;
    }

    bool CheckConstraint(vector<string>& v, string& s, int low, int high) {
        high = min(high, (int) s.size());
        for (string& x : v) {
            if (!CheckString(x, low, high)) {
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
            "dododoraemon",
            "4",
            "do",
            "dodo",
            "dora",
            "o"
        });
        Output({
            "3",
            "2",
            "1",
            "4"
        });
    }
    void BeforeTestCase() {
        S.clear();
        P.clear();
        ans.clear();
    }

    void TestCases() {
        for (int i = 0; i < 5; i++) {
            CASE(
                generateRandomString(rnd.nextInt(1, SMAX), S, 1, 26),
                Q = rnd.nextInt(1, QMAX),
                generateRandomQuery(Q, S, P);
            );
        }
        for (int i = 0; i < 15; i++) {
            CASE(
                generateRandomString(rnd.nextInt(1, SMAX), S, 1, 26),
                Q = rnd.nextInt(1, QMAX),
                generateRandomQuerySubstrings(Q, S, P);
            );
        }
        for (int i = 0; i < 5; i++) {
            CASE(
                generateRandomString(rnd.nextInt(1, SMAX), S, 1, 2),
                Q = rnd.nextInt(1, QMAX),
                generateRandomQuerySubstrings(Q, S, P);
            );
        }
        CASE(
            generateRandomString(rnd.nextInt(1, SMAX), S, 1, 1),
            Q = rnd.nextInt(1, QMAX),
            generateRandomQuerySubstrings(Q, S, P);
        );
    }

private:
    void generateRandomString(int N, string& S, int l, int r) {
        S.resize(N);
        for (int i = 0; i < N; i++) {
            int cur = rnd.nextInt(l, r) - 1;
            S[i] = char(int('a') + cur);
        }
    }

    void generateSubstring(string& S, string& P) {
        int len = S.size();
        int l = rnd.nextInt(0, len - 1);
        int r = rnd.nextInt(l, len - 1);
        P = S.substr(l, r - l + 1);
    }
    
    void generateRandomQuery(int Q, string& S, vector<string>& P) {
        int len = S.size();
        P.resize(Q);
        for (int i = 0; i < Q; i++) {
            generateRandomString(rnd.nextInt(1, len), P[i], 1, 26);
        }
    }

    void generateRandomQuerySubstrings(int Q, string& S, vector<string>& P) {
        P.resize(Q);
        for (int i = 0; i < Q; i++) {
            generateSubstring(S, P[i]);
        }
    }
};
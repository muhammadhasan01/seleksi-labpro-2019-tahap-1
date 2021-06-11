#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int SMAX = 1e5;
    const int QMAX = 1e2;
    const int PMAX = 3e2;

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
        TimeLimit(1.5);
        MemoryLimit(256);
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
                cerr << s.size() << " => " << x.size() << '\n';
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
                generateRandomQuery(Q, S, P, PMAX);
            );
        }
        for (int i = 0; i < 5; i++) {
            CASE(
                generateRandomString(rnd.nextInt(1, SMAX), S, 1, 26),
                Q = rnd.nextInt(QMAX / 2, QMAX),
                generateRandomQuerySubstrings(Q, S, P, PMAX);
            );
        }
        for (int i = 0; i < 10; i++) {
            CASE(
                generateRandomString(rnd.nextInt(1, SMAX), S, 1, rnd.nextInt(1, 5)),
                Q = QMAX,
                generateRandomQuerySubstrings(Q, S, P, PMAX);
            );
        }
        for (int i = 0; i < 10; i++) {
            CASE(
                generateRandomString(rnd.nextInt(1, SMAX), S, 1, 2),
                Q = QMAX,
                generateRandomQuerySubstrings(Q, S, P, PMAX);
            );
        }
        CASE(
            generateRandomString(rnd.nextInt(1, SMAX), S, 1, 1),
            Q = QMAX,
            generateRandomQuerySubstrings(Q, S, P, PMAX);
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

    void generateSubstring(string& S, string& P, int hgh) {
        int len = S.size();
        int l = rnd.nextInt(0, len - 1);
        int r = rnd.nextInt(l, min(l + hgh - 1, len - 1));
        P = S.substr(l, r - l + 1);
    }
    
    void generateRandomQuery(int Q, string& S, vector<string>& P, int hgh) {
        int len = S.size();
        P.resize(Q);
        for (int i = 0; i < Q; i++) {
            generateRandomString(rnd.nextInt(1, min(hgh, len)), P[i], 1, 26);
        }
    }

    void generateRandomQuerySubstrings(int Q, string& S, vector<string>& P, int hgh) {
        P.resize(Q);
        for (int i = 0; i < Q; i++) {
            generateSubstring(S, P[i], hgh);
        }
    }
};
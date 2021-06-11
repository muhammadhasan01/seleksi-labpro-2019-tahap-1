#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int MAXLEN = 20;

    int N;
    vector<string> S;
    int ans;

    void InputFormat() {
        LINE(N);
        LINES(S) % SIZE(N);
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= NMAX);
        CONS(CheckConstraint(S));
    }

private:
    bool CheckConstraint(vector<string>& v) {
        for (const string& x : v) {
            if (x.size() < 1 || x.size() > MAXLEN) {
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
            "5",
            "kasur",
            "rusak",
            "dean",
            "edan",
            "hasan"
        });
        Output({
            "3",
        });
    }
    void BeforeTestCase() {
        S.clear();
    }

    void TestCases() {
        for (int i = 0; i < 10; i++) {
            CASE(N = rnd.nextInt(1, 1000), generateRandomStrings(N));
        }
        for (int i = 0; i < 15; i++) {
            CASE(N = rnd.nextInt(1000, NMAX), generateRandomStrings(N));
        }
        for (int i = 0; i < 10; i++) {
            CASE(N = rnd.nextInt(1, 1000), generateAnagramFilledStrings(N, 10));
        }
        for (int i = 0; i < 15; i++) {
            CASE(N = rnd.nextInt(1000, NMAX), generateAnagramFilledStrings(N, MAXLEN));
        }
        for (int i = 0; i < 10; i++) {
            CASE(N = NMAX, generateAnagramFilledStrings(N, MAXLEN));
        }
    }

private:
    void generateRandomStrings(int N) {
        S.resize(N);
        for (int i = 0; i < N; i++) {
            generateRandomString(rnd.nextInt(1, MAXLEN), S[i]);
        }
    }

    void generateRandomString(int N, string& S) {
        S.resize(N);
        for (int i = 0; i < N; i++) {
            S[i] = char(int('a') + rnd.nextInt(0, 25));
        }
    }

    void generateAnagramFilledStrings(int N, int maxLen) {
        S.resize(N);
        int cnt = 0;
        while (cnt < N) {
            string unique;
            generateUniqueString(rnd.nextInt(1, maxLen), unique);
            do {
                S[cnt++] = unique;
                if (cnt == N) {
                    random_shuffle(S.begin(), S.end());
                    return;
                }
            } while(next_permutation(unique.begin(), unique.end()));
        }
    }

    void generateUniqueString(int N, string& S) {
        string all = "abcdefghijklmnopqrstuvwxyz";
        random_shuffle(all.begin(), all.end());
        S = all.substr(0, N);
        sort(S.begin(), S.end());
    }
};
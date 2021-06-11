#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;

using ll = long long;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int WMAX = 1e9;

    int N, M;
    int A, B, C;
    vector<int> U, V, W;
    int X;
    ll SX;

    void InputFormat() {
        LINE(N, M);
        LINE(A, B, C);
        LINES(U, V, W) % SIZE(M);
    }

    void OutputFormat() {
        LINE(X, SX);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(3 <= N && N <= NMAX);
        CONS(N - 1 <= M && M <= NMAX);
        CONS(eachElementBetween(U, 1, N));
        CONS(eachElementBetween(V, 1, N));
        CONS(eachElementBetween(W, 1, WMAX));
        // CONS(noSelfLoop(U, V));
        // CONS(isConnected(N, U, V));
    }

private:
    bool eachElementBetween(const vector<int>& v, int lo, int hi) {
        for (int x : v) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }

    bool allAreEqual(const vector<int>& v) {
        for (int x : v) {
            if (x != v[0]) {
                return false;
            }
        }
        return true;
    }

    bool noSelfLoop(const vector<int>& u, const vector<int>& v) {
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == v[i]) {
                return false;
            }
        }
        return true;
    }

    bool isConnected(int n, const vector<int>& u, const vector<int>& v) {
        vector<bool> isVisited(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < u.size(); i++) {
            adj[u[i]].push_back(v[i]);
            adj[v[i]].push_back(u[i]);
        }
        int numNodesVisited = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            if (isVisited[now]) {
                continue;
            }
            isVisited[now] = true;
            ++numNodesVisited;
            for (int v : adj[now]) {
                q.push(v);
            }
        }
        return numNodesVisited == n;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5 6",
            "3 4 5",
            "1 2 10",
            "2 3 3",
            "1 4 5",
            "1 5 4",
            "2 4 50",
            "4 5 30"

        });
        Output({
            "1 13"
        });
    }

    void BeforeTestCase() {
        U.clear();
        V.clear();
        W.clear();
    }

    void TestCases() {
        CASE(N = 3, M = 3, generateABC(N), randomGraph(N, M, U, V), randomWeight(M, W, 1, 100));
        for (int i = 0; i < 5; i++) {
          CASE(N = rnd.nextInt(3, 10), M = rnd.nextInt(N - 1, min(1ll * N * (N - 1) / 2, 1ll * NMAX)), generateABC(N), randomGraph(N, M, U, V), randomWeight(M, W, 1, 100));
        }
        for (int i = 0; i < 10; i++) {
          CASE(N = rnd.nextInt(10, 1000), M = rnd.nextInt(N - 1, min(1ll * N * (N - 1) / 2, 1ll * NMAX)), generateABC(N), randomGraph(N, M, U, V), randomWeight(M, W, 1, WMAX));
        }
        for (int i = 0; i < 40; i++) {
          CASE(N = rnd.nextInt(1000, NMAX), M = rnd.nextInt(N - 1, min(1ll * N * (N - 1) / 2, 1ll *NMAX)), generateABC(N), randomGraph(N, M, U, V), randomWeight(M, W, 1, WMAX));
        }
    }

private:
    void generateABC(int N) {
      A = rnd.nextInt(1, N - 2);
      B = rnd.nextInt(A + 1, N - 1);
      C = rnd.nextInt(B + 1, N);
    }

    void randomWeight(int m, vector<int>& w, int minW = 1, int maxW = 1000) {
        for (int i = 0; i < m; i++) {
            w.push_back(rnd.nextInt(minW, maxW));
        }
    }

    void renumber(int n, vector<int>& u, vector<int>& v) {
        vector<int> permutation;
        for (int i = 0; i < n; i++) {
            permutation.push_back(i);
        }
        rnd.shuffle(permutation.begin(), permutation.end());
        for (int i = 0; i < u.size(); i++) {
            u[i] = permutation[u[i]];
            v[i] = permutation[v[i]];
        }
    }

    void randomTree(int n, vector<int>& u, vector<int>& v) {
        for (int i = 1; i < n; i++) {
            u.push_back(i);
            v.push_back(rnd.nextInt(0, i - 1));
        }
        renumber(n, u, v);
    }

    void randomGraph(int n, int m, vector<int>& u, vector<int>& v) {
        randomTree(n, u, v);
        map<pair<int, int>, bool> alr;
        for (int i = 0; i < u.size(); i++) {
          int tu = u[i], tv = v[i];
          if (tu > tv) swap(tu, tv);
          alr[{tu, tv}] = true;
        }
        while (u.size() < m) {
            int newU = rnd.nextInt(0, n - 2);
            int newV = rnd.nextInt(newU + 1, n - 1);
            if (alr.count({newU, newV})) {
              continue;
            }
            alr[{newU, newV}] = true;
            u.push_back(newU);
            v.push_back(newV);
        }
        for (int i = 0; i < m; i++) {
          u[i]++; v[i]++;
        }
    }
};
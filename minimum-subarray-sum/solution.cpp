#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long ans = INF, cur = INF;
    for (int i = 0; i < N; i++) {
        cur += A[i];
        if (A[i] < cur) {
            cur = A[i];
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}
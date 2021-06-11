#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    vector<int> P(N + 1), W(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> P[i] >> W[i];
    }
    vector<vector<long long>> dp(N + 1, vector<long long>(K + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= W[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i]] + P[i]);
            }
        }
    }
    cout << dp[N][K] << '\n';

    return 0;
}
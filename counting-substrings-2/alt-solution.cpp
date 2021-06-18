#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.length();
    int q;
    cin >> q;
    while (q--) {
        string p;
        cin >> p;
        int m = p.size();
        vector<int> lps(m);
        for (int i = 1; i < m; i++) {
            int j = lps[i - 1];
            while (j > 0 && p[i] != p[j]) {
                j = lps[j - 1];
            }
            if (p[i] == p[j]) {
                j++;
            }
            lps[i] = j;
        }
        int ans = 0;
        int i = 0, j = 0;
        while (i < n) {
            if (s[i] == p[j]) {
                i++, j++;
            }
            if (j == m) {
                ++ans;
                j = lps[j - 1];
            }
            if (i < n && s[i] != p[j]) {
                if (j > 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;
    while (q--) {
        string p;
        cin >> p;
        int m = p.size();
        int cnt = 0;
        for (int i = 0; i < n - m + 1; i++) {
            if (s.substr(i, m) == p) {
                ++cnt;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
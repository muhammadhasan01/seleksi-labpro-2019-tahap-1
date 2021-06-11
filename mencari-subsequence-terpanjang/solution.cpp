#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define INF 1234567890
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int x[n + 5], y[n + 5], z[n+5];
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    int answer = 1;
    int ans[n + 5];
    ans[1] = 1;
    for (int i = 2; i <= n; i++) {
        ans[i] = 1;
        for (int j = 1; j < i; j++) {
            if (x[i] > x[j] && y[i] > y[j] && z[i] > z[j] && ans[i] < ans[j] + 1) ans[i] = ans[j] + 1;
        }
        answer = max(answer, ans[i]);
    }
    cout << answer << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
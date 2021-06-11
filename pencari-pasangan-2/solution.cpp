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
    int n, l, r;
    cin >> n >> l >> r;
    int a[n+5];
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= r) break;    // a[i]+a[j] pasti > r
        int minj = l - a[i], maxj = r - a[i];   // cari jumlah bilangan yang diantara minj dan maxj
        int l = i+1, r = n;
        int ansl = -1, ansr = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] <= maxj) {
                ansr = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        l = i+1; r = n;
        while (l <= r) {
            int m = (l + r) / 2;
            if (a[m] >= minj) {
                ansl = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (ansl != -1 && ansr != -1) ans += ansr - ansl + 1;
    }
    cout << ans << endl;
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
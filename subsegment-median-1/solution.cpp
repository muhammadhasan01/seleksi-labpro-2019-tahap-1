#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int MX = 1e9;

int n;
vector<int> ar;
vector<vector<int>> stree;
int q;

void build(int v, int tl, int tr){
    if (tl == tr){
        stree[v].pb(ar[tl]);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    stree[v].resize(tr - tl + 1);
    merge(stree[v * 2].begin(), stree[v * 2].end(), stree[v * 2 + 1].begin(), stree[v * 2 + 1].end(), stree[v].begin());
}
int count_under(int v, int tl, int tr, int l, int r, int x){
    if (tl > tr || tr < l || r < tl) return 0;
    if (l <= tl && tr <= r){
        int ret = 0;
        int l = 0, r = tr - tl;
        while (l <= r){
            int m = (l + r) / 2;
            if (stree[v][m] <= x){
                ret = m + 1;
                l = m + 1;
            } else{
                r = m - 1;
            }
        }
        return ret;
    }
    int tm = (tl + tr) / 2;
    return count_under(v * 2, tl, tm, l, r, x) + count_under(v * 2 + 1, tm + 1, tr, l, r, x);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    stree.resize(n * 4, vector<int>());
    ar.resize(n + 1);
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    build(1, 1, n);
    cin >> q;
    while (q--){
        int a, b;
        cin >> a >> b;
        int x = (b - a + 1 + 1) / 2;
        int ans;
        int l = 1, r = MX;
        while (l <= r){
            int m = (l + r) / 2;
            if (count_under(1, 1, n, a, b, m) >= x){
                ans = m;
                r = m - 1;
            } else{
                l = m + 1;
            }
        }
        cout << ans << el;
    }

    return 0;
}
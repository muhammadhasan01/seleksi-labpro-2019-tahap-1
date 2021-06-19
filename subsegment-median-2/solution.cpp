#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, q;
vector<int> ar;
vector<pii> arid;
vector<vector<int>> stree;

void build(int v, int tl, int tr){
    if (tl == tr){
        stree[v].pb(arid[tl].second);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    stree[v].resize(tr - tl + 1);
    merge(stree[v * 2].begin(), stree[v * 2].end(), stree[v * 2 + 1].begin(), stree[v * 2 + 1].end(), stree[v].begin());
}
int query(int v, int tl, int tr, int l, int r, int pos){
    if (tl == tr) return stree[v].back();
    int tm = (tl + tr) / 2;
    int cnt = upper_bound(stree[v * 2].begin(), stree[v * 2].end(), r) - lower_bound(stree[v * 2].begin(), stree[v * 2].end(), l);
    if (cnt >= pos) return query(v * 2, tl, tm, l, r, pos);
    return query(v * 2 + 1, tm + 1, tr, l, r, pos - cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    ar.resize(n);
    stree.resize(n * 4);
    for (int i=0;i<n;i++){
        cin >> ar[i];
        arid.pb(mp(ar[i], i));
    }
    sort(arid.begin(), arid.end());
    build(1, 0, n - 1);
    
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << ar[query(1, 0, n - 1, --l, --r, (r - l) / 2 + 1)] << el;
    }
    
	return 0;
}

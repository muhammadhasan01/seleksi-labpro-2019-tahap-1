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
const int INF = 1e9 + 10;

int n;
vector<pii> ar;
int q;
vector<pii> quer;
int ans[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ar.resize(n + 1);
    for (int i=0;i<n;i++){
        cin >> ar[i].fi >> ar[i].se;
    }
    ar[n] = {INF, INF};
    sort(ar.begin(), ar.end(), greater<pii>());
    cin >> q;
    for (int i=0;i<q;i++){
        int a;
        cin >> a;
        quer.pb(mp(a, i));
    }
    sort(quer.begin(), quer.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int cur = 0;
    for (auto &x : quer){
        while (ar.back().fi <= x.fi){
            cur++;
            pq.push(ar.back().se);
            ar.pop_back();
        }
        while (!pq.empty() && pq.top() < x.fi){
            cur--;
            pq.pop();
        }
        ans[x.se] = cur;
    }
    for (int i=0;i<q;i++){
        cout << ans[i] << el;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
const ll MAXDIS = 1ll * 1e9 * 1e5;

vector<pair<int, ll>> adj[N];
ll disA[N], disB[N], disC[N];
int n, m, a, b, c;

using pli = pair<ll, int>;
using pil = pair<int, ll>;

void dijk(int source, ll *dis) {
  for (int i = 1; i <= n; i++) {
    dis[i] = i == source ? 0 : MAXDIS;
  }
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  pq.push({0ll, source});
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    for (const pil& vw: adj[u]) {
      int v; ll w;
      tie(v, w) = vw;
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        pq.push({dis[v], v});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  cin >> a >> b >> c;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  
  dijk(a, disA);
  dijk(b, disB);
  dijk(c, disC);
  
  int x = 0;
  ll sx = MAXDIS;
  for (int i = 1; i <= n; i++) {
    ll si = max({disA[i], disB[i], disC[i]});
    if (si < sx) {
      x = i;
      sx = si;
    }
  }
  cout << x << ' ' << sx << '\n';
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  set<string> alr;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    alr.insert(s);
  }
  cout << alr.size() << '\n';
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define F first
#define S second

vector<string> pows;

void solve() {
  string s;
  cin >> s;

  int n = s.size();

  int ans = INT_MAX;

  for (auto &x : pows) {

    int size = x.size();

    int i, j, c;
    i = j = c = 0;

    while (i < n && j < size) {

      if (x[j] == s[i]) {
        j++, i++, c++;
      } else {
        i++;
      }
    }

    ans = min(ans, abs(c - n) + abs(c - size));
  }
  cout << ans << endl;
}

int main() {

  // make cin and cout input and output faster
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll k = 1;

  for (int i = 0; i < 64; i++) {
    pows.push_back(to_string(k << i));
  }

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}

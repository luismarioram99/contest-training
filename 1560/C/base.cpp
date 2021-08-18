#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve() {
  ll k;
  cin >> k;

  ll q = ceil(sqrt(k));
  ll p = (q - 1) * (q - 1);

  ll r = k - p;

  if (r <= q) {
    cout << r << " " << q << endl;
  } else {
    cout << q << " " << (2 * q - r) << endl;
  }
}

int main() {

  // make cin and cout input and output faster
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}

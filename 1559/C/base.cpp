#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve() {

  int n;
  cin >> n;
  vi a(n);
  for (auto &x : a) {
    cin >> x;
  };

  if (a[0] == 1) {
    cout << n + 1 << " ";
    for (int i = 1; i <= n; i++)
      cout << i << " ";
    cout << endl;
    return;
  }

  if (n == 1) {
    cout << "1 2" << endl;
    return;
  }

  cout << 1 << " ";
  bool been = false;
  for (int i = 1; i < n; i++) {

    if (!been && a[i - 1] == 0 && a[i] == 1) {
      cout << n + 1 << " ";
      been = true;
    }
    cout << i + 1 << " ";
  }

  if (!been) {
    cout << n + 1 << " ";
  }

  cout << endl;
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

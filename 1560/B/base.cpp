#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve() {
  int a, b, c;

  cin >> a >> b >> c;
  if (a > b)
    swap(a, b);
  int n = (b - a) * 2;

  if (c > n || a > n || b > n) {
    cout << -1 << endl;
    return;
  }

  int d = c + n / 2;
  if (d > n)
    d = c - n / 2;

  cout << d << endl;
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

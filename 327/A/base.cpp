#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<pl> vll;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define F first
#define S second

void solve() {

  int n;
  cin >> n;

  vi a(n);
  int sum = 0;
  for (auto &x : a) {
    cin >> x;
    sum += x;
  }

  if (sum == n) {
    cout << n - 1 << endl;
    return;
  }

  int max_res = sum;
  int res;

  for (int i = 0; i < n; i++) {

    for (int j = i; j < n; j++) {

      res = sum;

      for (int k = i; k <= j; k++) {

        if (a[k] == 0) {
          res += 1;
        } else {
          res -= 1;
        }
      }
      max_res = max(max_res, res);
    }
  }
  cout << max_res << endl;
}

int main() {
  // make cin and cout input and output faster
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while (t--)
    solve();
}
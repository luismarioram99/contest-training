#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve() {
  int k;
  cin >> k;

  int i = 1;
  for (; i <= k; i++) {
    if (i % 3 == 0 || i % 10 == 3) {
      k++;
    }
  }
  cout << k << endl;
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

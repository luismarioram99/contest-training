#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve() {
  ll n;
  cin >> n;

  ll t = n / 3;

  ll c1, c2;
  c1 = t;
  c2 = t;

  if (n % 3 == 2) {
    c2++;
  } else if (n % 3 == 1) {
    c1++;
  }

  cout << c1 << " " << c2 << endl;
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

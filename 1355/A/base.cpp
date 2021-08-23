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

ll complement(ll a) {

  int min_dig, max_dig;
  min_dig = 10;
  max_dig = 0;

  int d;
  while (a > 0) {
    d = a % 10;
    a /= 10;
    min_dig = min(min_dig, d);
    max_dig = max(max_dig, d);
  }

  return min_dig * max_dig;
}

void solve() {
  ll a1, k;
  cin >> a1 >> k;

  ll res = a1;
  ll comp = 1;

  for (int i = 0; i < k - 1 && comp; i++) {
    comp = complement(res);
    res += comp;
    // cout << i + 1 << " " << res << endl;
  }
  cout << res << endl;
}

int main() {
  // make cin and cout input and output faster
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
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
  int n, x;
  cin >> n >> x;

  int o, e;
  o = e = 0;

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;

    if (k % 2)
      o++;
    else
      e++;
  }

  int q = min(x, o);

  for (int i = 1; i <= q; i += 2) {

    if (e >= x - i) {
      goto Yes;
    }
  }
  goto No;

Yes:
  cout << "Yes" << endl;
  return;
No:
  cout << "No" << endl;
  return;
}

int main() {

  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
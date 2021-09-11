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

int xornado(int x) {
  int r = x % 4;
  if (r == 0)
    return x;
  if (r == 1)
    return 1;
  if (r == 2)
    return x + 1;
  if (r == 3)
    return 0;

  return 0;
}

void solve() {

  int a, b;
  cin >> a >> b;

  int t = xornado(a - 1);

  if (t == b) {
    cout << a << endl;
    return;
  }

  int ans = a + 1;

  if ((t ^ b) == a) {
    ans++;
  }

  cout << ans << endl;
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
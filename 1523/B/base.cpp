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

  vl a(n);
  for (auto &x : a)
    cin >> x;

  cout << 6 * (n / 2) << endl;

  for (int i = 0; i < n; i += 2) {
    cout << 2 << " " << i + 1 << " " << i + 2 << endl;
    cout << 1 << " " << i + 1 << " " << i + 2 << endl;
    cout << 1 << " " << i + 1 << " " << i + 2 << endl;
    cout << 2 << " " << i + 1 << " " << i + 2 << endl;
    cout << 1 << " " << i + 1 << " " << i + 2 << endl;
    cout << 1 << " " << i + 1 << " " << i + 2 << endl;
  }
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
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

  int n, q;
  cin >> n >> q;

  int a;
  vi color_min(51, INT_MAX);

  for (int i = 1; i <= n; i++) {
    cin >> a;
    color_min[a] = min(color_min[a], i);
  }

  int t;
  int found;

  for (int i = 0; i < q; i++) {
    cin >> t;
    found = color_min[t];
    cout << found << " ";

    for (int j = 1; j <= 50; j++) {
      if (color_min[j] < found) {
        color_min[j]++;
      }
    }

    color_min[t] = 1;
  }

  cout << endl;
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
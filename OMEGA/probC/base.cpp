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

  vi data(n);
  for (auto &x : data)
    cin >> x;

  vii pre(n);
  vii pos(n);

  pre[0] = {data[0], 0};
  pos[n - 1] = {data[n - 1], n - 1};

  for (int i = 1; i < n; i++) {
    if (data[i] > pre[i - 1].F) {
      pre[i] = {data[i], i};
    } else {
      pre[i] = pre[i - 1];
    }
  }

  for (int i = n - 2; i >= 0; i--) {

    if (data[i] > pos[i + 1].F) {
      pos[i] = {data[i], i};
    } else {
      pos[i] = pos[i + 1];
    }
  }

  vi ans(n);

  for (auto x : pre)
    cout << x.F << " ";
  cout << endl;

  for (auto x : pos)
    cout << x.F << " ";
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
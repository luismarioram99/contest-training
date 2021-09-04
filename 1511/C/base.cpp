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
  int q;

  cin >> n >> q;

  vi min_pos(51, -1);

  int x;
  for (int i = 0; i < n; i++) {

    cin >> x;
    if (min_pos[x] == -1)
      min_pos[x] = i + 1;
  }

  vi ans;
  int t;
  for (int i = 0; i < q; i++) {

    cin >> t;

    ans.push_back(min_pos[t]);
    for (int j = 1; j < 51; j++) {
      if (min_pos[j] < min_pos[t]) {
        min_pos[j]++;
      }
    }
    min_pos[t] = 1;
  }

  for (auto x : ans)
    cout << x << " ";
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
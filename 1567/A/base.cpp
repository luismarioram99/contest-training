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

  string s;
  cin >> s;

  string ans;

  for (auto x : s) {
    if (x == 'L' || x == 'R') {
      ans += x;
    } else if (x == 'U') {
      ans += 'D';
    } else {
      ans += 'U';
    }
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
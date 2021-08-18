#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve1(string s) {

  int main_dig = s[0] - '0';
  int dig;
  bool flag = false;
  for (int i = 1; i < (int)s.size(); i++) {

    dig = s[i] - '0';
    if (dig > main_dig)
      flag = true;
  }

  main_dig += flag;

  for (int i = 0; i < (int)s.size(); i++) {
    cout << main_dig;
  }
  cout << endl;
}

void solve2(string s) {

  int d1 = s[0] - '0';
  int d2;
  int pos2;
  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] - '0' != d1) {
      d2 = s[i] - '0' pos2 = ;
    }
  }

  for (int i = 0)
}

void solve() {
  string s;
  int k;
  cin >> s >> k;

  if (k == 1) {
    solve1(s, k);
  } else {
    cout << "-" << endl;
  }
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

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
  int m;
  cin >> n >> m;

  string state;
  cin >> state;

  state = "0" + state + "0";

  string newstate;

  int count = 0;
  bool changes = true;

  while (changes && count < m) {

    newstate = state;
    changes = false;
    for (int i = 1; i <= n; i++) {

      if (state[i] == '0' && state[i - 1] != state[i + 1]) {
        newstate[i] = '1';
        changes = true;
      }
    }
    state = newstate;
    count++;
  }

  for (int i = 0; i < n; i++) {
    cout << state[i + 1];
  }
  cout << endl;
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
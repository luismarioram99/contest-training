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

string s;

int check() {
  // cout << s << endl;
  int team1 = 0;
  int team2 = 0;

  int shots1 = 5;
  int shots2 = 5;

  for (int i = 0; i < 10; i++) {
    // cout << i + 1 << ":\n";
    // cout << "shots " << shots1 << " " << shots2 << endl;
    // cout << "points " << team1 << " " << team2 << endl;

    // cout << team2 << " " << team1 + shots1 << endl;
    // cout << team1 << " " << team2 + shots2 << endl;

    if (team2 > team1 + shots1 || team1 > team2 + shots2) {
      return i;
    }

    if (!(i % 2)) {
      team1 += s[i] - '0';
      shots1--;
    } else {
      team2 += s[i] - '0';
      shots2--;
    }
  }
  return 10;
}

int min_shots(int pos) {

  if (pos == 10) {
    return check();
  }

  if (s[pos] != '?')
    return min_shots(pos + 1);

  s[pos] = '1';
  int shots1 = min_shots(pos + 1);
  s[pos] = '0';
  int shots0 = min_shots(pos + 1);

  s[pos] = '?';
  return min(shots1, shots0);
}

void solve() {
  cin >> s;
  cout << min_shots(0) << endl;
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
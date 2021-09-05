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

  string a, b;
  cin >> a >> b;

  int na = a.size();
  int nb = b.size();

  int min_moves = INT_MAX;

  for (int ai = 0; ai < na; ai++) {

    for (int aj = na - 1; aj >= ai; aj--) {

      for (int bi = 0; bi < nb; bi++) {

        for (int bj = nb - 1; bj >= bi; bj--) {

          string c = a.substr(ai, aj - ai + 1);
          string d = b.substr(bi, bj - bi + 1);

          if (c == d) {
            int da = na - (aj - ai + 1);
            int db = nb - (bj - bi + 1);

            min_moves = min(min_moves, da + db);
          }
        }
      }
    }
  }

  min_moves = min(min_moves, na + nb);
  cout << min_moves << endl;
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
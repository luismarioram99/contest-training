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

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void solve() {

  int h, w;
  cin >> h >> w;

  vector<vi> mat(h, vi(w, 0));

  bool flag;

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {

      if (i != 0 && i != (h - 1) && j != 0 && j != (w - 1))
        continue;

      flag = true;

      for (int k = 0; k < 8; k++) {

        int y = i + dy[k];
        int x = j + dx[k];

        if (x < 0 || x >= w)
          continue;

        if (y < 0 || y >= h)
          continue;

        if (mat[y][x] == 1) {
          flag = false;
        }
      }

      mat[i][j] = flag ? 1 : 0;
    }
  }

  for (auto x : mat) {
    for (auto y : x) {
      cout << y;
    }
    cout << endl;
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
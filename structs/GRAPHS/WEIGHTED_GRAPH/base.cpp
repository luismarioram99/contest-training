#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<pl> vll;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef vector<vi> graf;
typedef vector<vii> wgraf;

#define F first
#define S second

#define VISITED 1
#define UNVISITED 0

void solve() {

  int n, m;
  cin >> n >> m;

  wgraf g(n);

  int u, v, w;

  for (int i = 0; i < m; i++) {

    cin >> u >> v >> w;

    g[u].push_back({v, w});
    g[v].push_back({u, w});
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
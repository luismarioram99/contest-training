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

typedef pair<int, ii> edge;
/*
  F: weight
  S: {
    F: from
    S: to
  }
*/

#define F first
#define S second

#define VISITED 1
#define UNVISITED 0

wgraf g;
wgraf mst;
vi visited;
// O(V + ElogE)
// Deseamos O(ElogE)
void primm(int s) {

  priority_queue<edge, vector<edge>, greater<edge>> pq;
  pq.push({0, {s, s}});

  while (!pq.empty()) {

    ii u = {pq.top().S.S, pq.top().F};
    int from = pq.top().S.F;
    pq.pop();

    if (visited[u.F] == VISITED)
      continue;

    cout << "from: " << from << " {" << u.F << ", " << u.S << "} " << endl;

    if (from != s || u.F != s)
      mst[from].push_back({u.F, u.S});

    visited[u.F] = VISITED;

    for (auto v : g[u.F]) {

      cout << "\t"
           << "{" << v.F << ", " << v.S << "} " << endl;

      pq.push({v.S, {u.F, v.F}});
    }
  }
}

void solve() {

  int n, m;
  cin >> n >> m;

  g.resize(n);
  mst.resize(n);

  int u, v, w;

  for (int i = 0; i < m; i++) {

    cin >> u >> v >> w;

    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  for (int i = 0; i < n; i++) {

    cout << i << ":" << endl;
    for (auto x : g[i]) {
      cout << "\t" << x.F << " " << x.S << endl;
    }
  }

  visited.assign(n, UNVISITED);

  primm(0);

  for (int i = 0; i < n; i++) {

    cout << i << ":" << endl;
    for (auto x : mst[i]) {
      cout << "\t" << x.F << " " << x.S << endl;
    }
  }
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
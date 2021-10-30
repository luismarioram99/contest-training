#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<pl> vll;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef vector<vii> wgraf;
typedef pair<int, ii> edge;

#define F first
#define S second

class UnionFind {
private:
  vi p;
  vi h;
  int c;

public:
  UnionFind(int n) {
    p.resize(n);
    h.resize(n, 1);

    for (int i = 0; i < n; i++)
      p[i] = i;

    c = n;
  }

  int find(int e) {
    if (e == p[e])
      return e;

    return (p[e] = find(p[e]));
  }

  bool check(int u, int v) {
    int pu = find(u);
    int pv = find(v);

    return pu == pv;
  }

  bool join(int u, int v) {
    if (check(u, v)) {
      return false;
    }

    int pu = find(u);
    int pv = find(v);

    if (h[pu] < h[pv])
      swap(pu, pv);

    if (h[pu] == h[pv])
      h[pu]++;

    p[pv] = pu;
    c--;
    return true;
  }
  int count() { return c; }
};

void solve() {

  int n, m;
  cin >> n >> m;

  UnionFind uf(n);

  vector<edge> edges;

  wgraf mst(n);

  int u, v, w;

  for (int i = 0; i < m; i++) {

    cin >> u >> v >> w;

    edges.push_back({w, {u, v}});
  }

  sort(edges.begin(), edges.end());

  int edge_pos = 0;
  while (uf.count() > 1) {

    edge e = edges[edge_pos++];

    if (!uf.check(e.S.F, e.S.S)) {

      mst[e.S.F].push_back({e.S.S, e.F});
      // mst[e.S.S].push_back({e.S.F, e.F});

      uf.join(e.S.F, e.S.S);
    }
  }

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
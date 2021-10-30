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

#define UNVISITED 0
#define VISITED 1

int n, m;
vector<vi> g;
vi visited;
vi cats;
vi cats_max;
vi cats_until;
int res = 0;

void bfs(int s) {

  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visited[u] = VISITED;

    for (int v : g[u]) {

      if (visited[v] == UNVISITED) {

        if (cats[v]) {
          cats_until[v] = cats_until[u] + 1;
        } else {
          cats_until[v] = 0;
        }

        cats_max[v] = max(cats_until[v], cats_max[u]);

        q.push(v);
      }
    }

    if (g[u].size() == 1 && u != s && cats_max[u] < m) {
      // cout << u << endl;
      res++;
    }
  }
}
void solve() {

  cin >> n >> m;

  g.resize(n);
  cats.resize(n);
  cats_until.resize(n, 0);
  cats_max.resize(n, 0);

  visited.resize(n, UNVISITED);

  for (int i = 0; i < n; i++) {
    cin >> cats[i];
  }

  for (int i = 0; i < (n - 1); i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  bfs(0);
  cout << res << endl;
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
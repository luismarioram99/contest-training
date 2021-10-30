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

vi visited;
vector<vi> g;
void bfs(int s) {

  priority_queue<int, vi, greater<int>> q;
  q.push(s);
  // visited[s] = VISITED;

  while (!q.empty()) {
    int u = q.top();
    q.pop();

    cout << (u + 1) << " ";
    visited[u] = VISITED;

    for (auto x : g[u]) {

      if (visited[x] == UNVISITED) {
        q.push(x);
      }
    }
  }
}

void dfs(int u) {

  visited[u] = VISITED;
  cout << (u + 1) << " ";

  for (auto x : g[u]) {
    if (visited[x] == UNVISITED) {
      dfs(x);
    }
  }
}

void solve() {

  int n, m;
  cin >> n >> m;

  g.resize(n);

  for (int i = 0; i < m; i++) {

    int u, v;
    cin >> u >> v;
    u--, v--;

    g[u].push_back(v);
    g[v].push_back(u);
  }

  visited.assign(n, UNVISITED);

  for (auto x : g) {
    sort(x.begin(), x.end());
  }

  // bfs(0);
  dfs(0);
  cout << endl;
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
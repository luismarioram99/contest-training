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

void bfs(int s, vector<vi> &graph, vi &visited) {

  queue<int> q;
  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visited[u] = 1;
    cout << u << endl;

    for (int v : graph[u]) {
      if (!visited[v]) {
        q.push(v);
      }
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vi> adj(n);

  vi visited(n, 0);

  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int j = 1;
  for (auto u : adj) {
    cout << j++ << ": ";
    for (auto v : u) {
      cout << v + 1 << " ";
    }
    cout << endl;
  }

  bfs(0, adj, visited);
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
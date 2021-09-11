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
#define EXPLORED 1
#define VISITED 2

int cont = 0;

void dfs(int u, vector<vi> &graph, vi &visited, vi &parent, vi &dfs_num) {

  visited[u] = EXPLORED;
  dfs_num[u] = cont++;

  for (int v : graph[u]) {

    if (visited[v] == UNVISITED) {
      parent[v] = u;
      dfs(v, graph, visited, parent, dfs_num);
    }
  }

  visited[u] = VISITED;
}

void solve() {

  int n, m;
  cin >> n >> m;

  vector<vi> adj(n);

  vi visited(n, UNVISITED);
  vi parents(n, INT_MAX);
  vi dfs_num(n, INT_MAX);

  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  parents[0] = 0;
  cont = 0;

  for (int i = 0; i < n; i++) {

    if (visited[i] == UNVISITED) {
      dfs(0, adj, visited, parents, dfs_num);
    }
  }

  for (auto x : dfs_num)
    cout << x << " ";
  cout << endl;

  for (auto x : parents)
    cout << x << " ";
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
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

#define NON_VISITED 0
#define EXPLORED 1
#define VISITED 2

void dfs(int u, vector<vi> &graph, vi &visited) {

  visited[u] = EXPLORED;
  cout << u << endl;

  for (int v : graph[u]) {

    if (visited[v] == NON_VISITED) {
      dfs(v, graph, visited);
    }
  }

  visited[u] = VISITED;
}

void solve() {

  int n, m;
  cin >> n >> m;

  vector<vi> graph(n);

  int u, v;

  for (int i = 0; i < m; i++) {
    cin >> u >> v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vi visited(n, NON_VISITED);

  for (int i = 0; i < n; i++) {
    if (visited[i] == NON_VISITED) {
      dfs(i, graph, visited);
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
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

#define VISITED 1
#define UNVISITED 0

vi dfs_num, dfs_low, visited, S;
vector<vi> graph;

int dfsNum = 0;
int SCCcount = 0;

void tarjanSCC(int u) {
  dfs_num[u] = dfs_low[u] = dfsNum++;
  S.push_back(u);

  visited[u] = VISITED;

  for (auto v : graph[u]) {

    if (dfs_num[v] == UNVISITED) {
      tarjanSCC(v);
    }
    if (visited[v] == VISITED) {
      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
  }

  if (dfs_low[u] == dfs_num[u]) {
    cout << "SCC: " << ++SCCcount << endl;

    while (true) {
      int k = S.back();
      S.pop_back();

      visited[k] = UNVISITED;
      cout << k << " ";
      if (u == k)
        break;
    }
    cout << endl;
  }
}

void solve() {

  int n, m;
  cin >> n >> m;

  graph.resize(n);
  dfs_num.assign(n, UNVISITED);
  dfs_low.assign(n, UNVISITED);

  visited.assign(n, UNVISITED);
  S.clear();

  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
  }

  for (int i = 0; i < n; i++) {
    if (dfs_num[i] == UNVISITED) {
      tarjanSCC(i);
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
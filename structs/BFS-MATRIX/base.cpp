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

    for (int i = 0; i < (int)graph[u].size(); i++) {

      if (graph[u][i] && !visited[i]) {
        q.push(i);
      }
    }
  }
}

void solve() {

  int n, m;
  cin >> n >> m;

  vector<vi> mat(n, vi(n, 0));
  vi visited(n, 0);

  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--;
    v--;
    mat[u][v] = 1;
    mat[v][u] = 1;
  }

  for (auto u : mat) {
    for (auto v : u) {
      cout << v << " ";
    }
    cout << endl;
  }

  bfs(0, mat, visited);
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
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

#define UNVISITED -1

vi visited;
vi low_vis;
vi parents;

vi articulations;
vii bridges;

vector<vi> graph;

int cont = 0;
int s;
int rootChildren = 0;

void dfsArtAndBri(int u) {

  visited[u] = low_vis[u] = cont++;

  for (auto v : graph[u]) {

    if (visited[v] == UNVISITED) {
      parents[v] = u;
      if (u == s) {
        rootChildren++;
      }

      dfsArtAndBri(v);

      if (low_vis[v] >= visited[u]) {
        articulations.push_back(u);
      }
      if (low_vis[v] > visited[u]) {
        bridges.push_back(ii(min(u, v), max(u, v)));
      }

      low_vis[u] = min(low_vis[u], low_vis[v]);

    } else if (v != parents[u]) {

      low_vis[u] = min(low_vis[u], visited[v]);
    }
  }

  if (u == s && rootChildren > 1) {
    articulations.push_back(u);
  }
}

void solve() {

  int n, m;
  cin >> n >> m;

  graph.resize(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  visited.assign(n, UNVISITED);
  low_vis.assign(n, UNVISITED);
  parents.assign(n, -1);

  articulations.clear();
  bridges.clear();

  cont = 0;
  s = 0;
  parents[s] = s;

  dfsArtAndBri(s);

  cout << articulations.size() << endl;
  for (auto a : articulations) {
    if (a != s || rootChildren > 1)
      cout << a << " ";
  }
  cout << endl;

  cout << bridges.size() << endl;
  for (auto b : bridges) {
    cout << b.F << " " << b.S << endl;
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
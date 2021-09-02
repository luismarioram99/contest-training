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

void solve() {

  ii a, b, f;
  cin >> a.F >> a.S >> b.F >> b.S >> f.F >> f.S;

  int dx = abs(a.F - b.F);
  int dy = abs(a.S - b.S);

  if(a.F == f.F && f.F == b.F 
  && ((a.S > f.S && f.S > b.S) || (a.S < f.S && f.S < b.S))) {

    cout << 2 + dy << endl;
    return;
  }

  if(a.S == f.S && f.S == b.S 
  && ((a.F > f.F && f.F > b.F) || (a.F < f.F && f.F < b.F))) {

    cout << 2 + dx << endl;
    return;
  }

  cout << dx + dy << endl;



}

int main() {
  // make cin and cout input and output faster
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
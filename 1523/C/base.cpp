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

void printStack(stack<int> s) {
  vi v;
  while (!s.empty()) {
    v.push_back(s.top());
    s.pop();
  }
  reverse(v.begin(), v.end());
  for (int i = 0; i < (int)v.size() - 1; i++) {
    cout << v[i] << ".";
  }
  cout << v[v.size() - 1] << endl;
}

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (auto &x : a)
    cin >> x;

  stack<int> s;

  for (auto c : a) {

    if (c == 1) {
      s.push(c);
    } else {

      while (s.top() != (c - 1))
        s.pop();

      s.pop();
      s.push(c);
    }

    printStack(s);
  }
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
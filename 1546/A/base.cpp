#include <bits/stdc++.h>
#include <vector>
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

  int n;
  cin >> n;
  vi a(n), b(n);

  for (auto &x : a)
    cin >> x;
  for (auto &x : b)
    cin >> x;

  int suma = accumulate(a.begin(), a.end(), 0);
  int sumb = accumulate(b.begin(), b.end(), 0);

  if (suma != sumb) {
    cout << -1 << endl;
    return;
  }

  vii ans;

  bool flag;

  while (true) {

    int pos_element = -1;
    int neg_element = -1;

    flag = false;

    for (int j = 0; j < n; j++) {
      if (a[j] > b[j]) {
        pos_element = j;
      }
      if (a[j] < b[j]) {
        neg_element = j;
      }
      if (pos_element != -1 && neg_element != -1) {
        a[pos_element]--;
        a[neg_element]++;
        ans.push_back({pos_element + 1, neg_element + 1});
        flag = true;
        pos_element = -1;
        neg_element = -1;
      }
    }

    if (!flag) {
      cout << ans.size() << endl;
      for (auto &x : ans)
        cout << x.F << " " << x.S << endl;
      return;
    }
  }
}

int main() {

  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
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

  int n;
  cin >> n;

  vi a(n), b(n);

  for (auto &x : b)
    cin >> x;
  for (auto &x : a)
    cin >> x;

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int worst = n / 4;

  int curr_a = accumulate(a.begin() + worst, a.end(), 0);
  int curr_b = accumulate(b.begin() + worst, b.end(), 0);

  int curr = n;
  int rec = worst - 1;
  // cout << rec << endl;

  while (curr_a > curr_b && worst < n) {
    // cout << curr_a << " " << curr_b << endl;

    curr_b += 100;
    curr++;
    if (rec >= 0) {
      curr_a += a[rec];
      rec--;
    }
    if (!(curr % 4)) {
      curr_b -= b[worst];
      worst++;
    }
  }

  cout << curr - n << endl;
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
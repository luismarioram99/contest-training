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

  string s;
  int n;

  cin >> s >> n;
  int k = s.size();
  vi digits(k);

  for (int i = 0; i < k; i++) {
    digits[i] = s[i] - '0';
  }

  reverse(digits.begin(), digits.end());
  // for (auto x : digits)
  //   cout << x << " ";
  // cout << endl;

  vi nums(n, 0);

  for (int i = 0; i < k; i++) {

    if (digits[i] == 0)
      continue;

    for (int j = 0; j < n - 1; j++) {
      nums[j] += 1 * pow(10, i);
      digits[i]--;
    }

    nums[n - 1] += digits[i] * pow(10, i);
  }

  for (auto x : nums)
    cout << x << " ";
  cout << endl;
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
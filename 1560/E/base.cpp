#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define F first
#define S second

void solve() {
  string t;
  cin >> t;

  vector<pair<int, char>> last(30);
  vector<int> appears(30, 0);

  for (int i = 0; i < 30; i++) {
    last[i] = {INT_MAX, (char)('a' + i)};
  }

  for (int i = 0; i < (int)t.size(); i++) {

    int pos = t[i] - 'a';
    last[pos].F = i;

    appears[pos]++;
  }

  sort(last.begin(), last.end());

  string order = "";
  int i = 0;
  pair<int, char> element = last[0];
  while (element.F != INT_MAX) {
    order += element.S;
    element = last[++i];
  }

  int original_length = 0;

  for (int i = order.size() - 1; i >= 0; i--) {
    original_length += appears[order[i] - 'a'] / (i + 1);
  }

  string s = t.substr(0, original_length);

  string newt = s;
  string past_s = s;
  string append;

  for (int i = 0; i < (int)order.size(); i++) {
    append = "";
    for (int j = 0; j < (int)past_s.size(); j++) {
      if (order[i] != past_s[j]) {
        append += past_s[j];
      }
    }
    newt += append;
    past_s = append;
  }

  if (newt == t) {
    cout << s << " " << order << endl;
  } else {
    cout << -1 << endl;
  }
}

int main() {

  // make cin and cout input and output faster
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}

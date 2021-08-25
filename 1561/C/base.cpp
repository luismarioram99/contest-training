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

  vi ks(n);
  vi bs(n, -1);

  int a;

  for(int i = 0; i < n; i++){

    cin >> ks[i];    
    for(int j = 0; j < ks[i]; j++){
      cin >> a;
      // cout << a << " " << j << endl;
      bs[i] = max(bs[i], a - j); 
    }
  }

  vii temp;
  for(int i = 0; i < n; i++) temp.push_back(make_pair(bs[i], ks[i]));

  sort(temp.begin(), temp.end());

  int p = -1;
  int sum = 0;
  for(int i = 0; i < n; i++){

    // cout << temp[i].F << " " << temp[i].S << " " << sum << endl;

    p = max(p, temp[i].F - sum);
    sum += temp[i].S;

  }

  cout << p + 1 << endl;
  
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
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

  vi a(n);
  int p;
  int o = 0;
  int e = 0;
  for(auto &x: a){
    cin >> p;
    x = p%2;
    if(x){
      o ++;
    }else{
      e ++;
    }
  }

  if(abs(o - e) > 1){
    cout << -1 << endl;
    return;
  }

  int total = 0;
  int sup = 1;

  int def = 1 - a[0];

  for(int i = 1; i < n; i++){

    if(a[i] == def){
      total += abs(i - sup);
      sup += 2;
    }

  }
  cout << total << endl;

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
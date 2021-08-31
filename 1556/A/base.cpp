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

  ll c, d;
  cin >> c >> d;

  if(c == 0 && d == 0){
    cout << 0 << endl;
    return;
  }  

  if(c == d){
    cout << 1 << endl;
    return;
  }

  if(c > d){
    swap(c,d);
  }

  ll dif = d - c;

  if(dif%2){
    cout << -1 << endl;
  }else{
    cout << 2 << endl;
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
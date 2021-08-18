#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){

  int n; 
  cin >> n; 

  vi a(n), b(n);
  for(auto &x: b) cin >> x;
  for(auto &x: a) cin >> x;

  vi prefix_a(n+1,0), sufix_b(n+1,0);
  int sum = 0; 
  for(int i = 0; i < n; i++){
    prefix_a[i+1] = sum += a[i];
  }
  sum = 0;
  for(int i = n-1; i >= 0; i--){
    sufix_b[i] = sum += b[i];
  }

  // for(auto x: prefix_a) cout << x << " ";
  // cout << endl;
  // for(auto x: sufix_b) cout << x << " ";
  // cout << endl;

  int score = INT_MAX;

  for(int i = 0; i < n; i++){

    score = min(score, max(prefix_a[i], sufix_b[i+1]));

  }

  cout << score << endl;

}

int main() {

  //make cin and cout input and output faster
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;
  while(t--){
    solve();
  }

  return 0;
}

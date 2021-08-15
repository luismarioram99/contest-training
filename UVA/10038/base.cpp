#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){

  int n;
  if(!(cin >> n)) return;
  

  vi a(n);
  for(auto &x: a) cin >> x;

  vi b(n, 0);

  for(int i = 1; i < n; i++){

    int diff = abs(a[i] - a[i-1]);

    if(diff > n-1 || diff < 0){
      cout << "Not jolly" << endl;
      return;
    }

    b[diff] ++;
  }

  for(int i = 1; i < n; i++){
    if(b[i] != 1){ 
      cout << "Not jolly" << endl;
      return;
    }
  }
  cout << "Jolly" << endl;

}

int main() {

  //make cin and cout input and output faster
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // int t = 1;
  // cin >> t;
  while(!cin.eof()){
    solve();
  }

  return 0;
}

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

  vector<int> values(256, 0);

  char k;
  int p;

  for(int i = 0; i < n; i++){
    cin >> k >> p;
    values[(int) k] = p;
  }

  int m; 
  cin >> m;

  ll total = 0;
  string line;

  cin >> ws;

  for(int i = 0; i < m; i++){
    getline(cin, line);
    cin >> ws;
    for(auto x: line){
      total += values[x];
    };

  }

  ll dollars = total/100; 

  ll cents = total%100;

  printf("%lld.%02lld$\n", dollars, cents);  

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

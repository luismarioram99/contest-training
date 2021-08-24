#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


void solve(){
  int a, b;
  cin >> a >> b;
  
  int d = abs(a - b)/2;
  vi ans;
  for(int i = d; i <= a + b - d; i += (2 - (a+b)%2)){
    ans.push_back(i);
  }
  cout << ans.size() << endl;
  for(auto &x: ans) cout << x << " ";
  cout << endl;
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

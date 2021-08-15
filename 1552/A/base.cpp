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
  string s;
  cin >> s;

  string ss = s;
  sort(ss.begin(), ss.end());

  int cont = 0;
  for(int i=0; i<n; i++){
    if(ss[i] != s[i]){
      cont ++;
    }
  }
  cout << cont << endl;

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

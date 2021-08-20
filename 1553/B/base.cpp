#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void solve(){

  string s, t;
  cin >> s >> t;

  int n = s.size();
  int m = t.size();

  bool flag = false;
  bool each;

  for(int i = 0; i < n; i++){
    for(int r = n-1; r >= i; r--){
      each = true;

      int l = 2*r - m - i + 1;

      if(l < 0) continue;

      int k = 0;
      for(int c = i; c <= r; c++){
        if(s[c] != t[k++]){
          each = false;
          break; 
        }
      }

      for(int c = r-1; c >= l; c--){
        if(s[c] != t[k++]){
          each = false;
          break; 
        }
      }

      flag = flag||each;
    }
  }

  if(flag) goto YES;
  else goto NO;


  YES: 
    cout << "YES" << endl;
    return;
  NO:
    cout << "NO" << endl;
    return;

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

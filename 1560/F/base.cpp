#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

string solve1(string s) {

  int n = s.size();
  string res;
  for(int i = 9; i >= 1; i--){
    
    string k(n, ('0' + i));

    if(k >= s) res = k;
  }
  return res;

}

string solve2(string s) {

  string res = solve1(s);

  for(char a = '0'; a <= '9'; a++){
    for(char b = '0'; b <= '9'; b++){

      bool ok = true;

      for(int i = 0; i < (int)s.size(); i++){

        if(s[i] < b){

          string t = s; 

          if(t[i] < a) t[i] = a;
          else t[i] = b;
           
          for(int j = i + 1; j < (int)s.size(); j++){
            t[j] = a;
          }

          if(res > t) res = t;

        }
        if(s[i] != a && s[i] != b){
          ok = false;
          break;
        }
      }

      if(ok) return s;

    }

  }

  return res;
}

void solve() {
  string s;
  int k;
  cin >> s >> k;


  if (k == 1) {
    cout << solve1(s) << endl; 
  } else {
    cout << solve2(s) << endl;
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

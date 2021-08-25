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

  int n, a, b;
  cin >> n >> a >> b;

  string s; 
  cin >> s;

  int def = a*n;

  if(b >= 0){
    cout << (def + b*n) << endl;
    return;
  }else{

    int g = 1;
    int curr = s[0];
    for(int i = 1; i < n; i++){
      if(curr != s[i]){
        curr = s[i];
        g++;
      }
    }

    int m =(g/2)+1;
    
    cout << (def + b*m) << endl;

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
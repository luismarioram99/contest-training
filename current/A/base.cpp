#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

void f(int &a, int &b, bool &c){

  if(a < b){
    swap(a, b);
    c = true;
  }

}

void solve(){ 
  int n;
  cin >> n;

  vi arr(n);
  for(auto &x: arr) cin >> x;

  bool calledo = true;
  bool callede = true;
  int count = 0;
  int i = 1;
  while(calledo && callede){

    if(!(i%2)) calledo = false;
    else callede = false;
  
    for(int j = !(i%2); j < n-1; j += 2){
      f(arr[j], arr[j+1], !(i%2)?calledo:callede);
    }

    if(calledo && callede){
      count ++;
    }

    i++;
    i %= 2;

  }

  cout << count << endl;

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

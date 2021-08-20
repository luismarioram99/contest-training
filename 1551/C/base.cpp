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

  vector<vi> f(5, vi(n));

  vector<string> words(n);
  for(auto &x: words) cin >> x;

  for(char i = 'a'; i <= 'e'; i++){

    for(int j = 0; j < n; j++){

      int c = 0;
      for(auto x: words[j]){
        if(x == i) c++;
      }

      f[i - 'a'][j] = (2*c) - words[j].size();
    }
  }

  // for(auto arr: f){
  //   for(auto x: arr){
  //     cout << x << " ";
  //   }
  //   cout << endl;
  // }

  int max_value = 0;
  int count; 
  int sum;  


  for(auto arr: f){
    sort(arr.begin(), arr.end(), greater<int>());

    // for(auto x: arr){
    //   cout << x << " ";
    // }
    // cout << endl;

    if(arr[0] <= 0){
      max_value = max(max_value, 0);
      // cout << "here" << endl;
      continue;
    }

    count = 1;
    sum = arr[0];

    for(int i = 1; i < n; i++){
      sum += arr[i];
      if(sum > 0) count ++;
    }
    max_value = max(max_value, count);

  }

  cout << max_value << endl;  

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

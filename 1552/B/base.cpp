#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool isBetter(int a[], int b[]){
    int cont = 0;
    for(int j = 0; j < 5; j++){

      if(a[j] < b[j])
        cont ++;

    }

    return cont >= 3;
} 


void solve(){
  int n;
  cin >> n;

  vector<int [5]> players(n);

  for(auto x: players)
    for(int i = 0; i < 5; i++)
      cin >> x[i];

  int* max_player  = new int[5];
  for(int i = 0; i < 5; i++) max_player[i] = INT_MAX;
  int max_pos = -1;

  for(int i = 0; i < n; i++){

    if(isBetter(players[i], max_player)){
      max_player = players[i];
      max_pos = i;
    }

  }

  for(int i = 0; i < n; i++){

    if(i == max_pos) continue;

    if(!isBetter(max_player, players[i])){
      cout << -1 << endl;
      return;
    }


  }


  cout << max_pos + 1 << endl;




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

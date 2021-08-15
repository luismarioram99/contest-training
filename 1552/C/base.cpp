#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

bool intersect(ii c, ii d){
  if(c.first > d.first) swap(c, d);
  return c.second > d.first && c.second < d.second;
}

void solve(){
  int n, k;
  cin >> n >> k;

  vector<ii> chords;
  vector<bool> used(2*n+1, false); 

  for(int i = 0; i < k; i++){
    int x, y;
    cin >> x >> y;
    if(x > y) swap(x,y);
    chords.push_back(ii(x,y));
    used[x] = used[y] = true;
  }

  vi unused;

  for(int i = 1; i <= 2*n; i++){
    if(!used[i]) unused.push_back(i); 
  }

  for(int i = 0; i < n-k; i++){
    chords.push_back(ii(unused[i], unused[i+n-k]));
  }

  int ans = 0;

  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      ans += intersect(chords[i], chords[j]);
    }
  }
  
  cout << ans << endl;

}

int main(){

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

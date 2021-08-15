#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi parents1;
vi height1;
vi parents2;
vi height2;

void init(int n){

  parents1.resize(n);
  parents2.resize(n);

  height1.resize(n,1);
  height2.resize(n,1);

  for(int i = 0; i < n; i++){
    parents1[i] = i;
    parents2[i] = i;
  }  

}

int find1(int e){

  if(parents1[e] == e){
    return e;
  }

  return parents1[e] = find1(parents1[e]);

}

int find2(int e){

  if(parents2[e] == e){
    return e;
  }

  return parents2[e] = find2(parents2[e]);

}

bool check1(int a, int b){
  int pa = find1(a);
  int pb = find1(b);

  return pa == pb;

}

bool check2(int a, int b){
  
  int pa = find2(a);
  int pb = find2(b);

  return pa == pb;
}

bool join1(int a, int b){

  if(check1(a, b)) return false;

  if(height1[a] < height1[b]){
    swap(a, b);
  }

  if(height1[a] == height1[b])
    height1[a] ++;

  int pa = find1(a);
  int pb = find1(b);

  parents1[pb] = pa;
  return true;


}

bool join2(int a, int b){

  if(check2(a, b)) return false;

  if(height2[a] < height2[b]){
    swap(a, b);
  }

  if(height2[a] == height2[b])
    height2[a] ++;

  int pa = find2(a);
  int pb = find2(b);

  parents2[pb] = pa;
  return true;

}

void solve(){

  int n;
  cin >> n;

  init(n);

  int m1, m2;
  cin >> m1 >> m2;

  int a, b;

  for(int i = 0; i < m1; i++){
    cin >> a >> b;
    join1(a-1, b-1);
  }
  for(int i = 0; i < m2; i++){
    cin >> a >> b;
    join2(a-1, b-1);
  }

  int cont = 0;
  vii add;

  for(int i = 0; i < n; i++){

    for(int j = i+1; j < n; j++){

      if(!check1(i,j) && !check2(i,j)){

        cont ++;
        add.push_back({i, j});
        join1(i, j);
        join2(i, j);
      }

    }

  }

  cout << cont << endl;
  for(auto x: add){
    cout << x.first+1 << " " << x.second+1 << endl;
  }

}

int main() {

  //make cin and cout input and output faster
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  // cin >> t;
  while(t--){
    solve();
  }

  return 0;
}

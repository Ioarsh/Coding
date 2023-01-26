#include<iostream>
#include <vector>
#include<cmath>
using namespace std;

#define MAX_N  100000

int n,m;

vector<int> adj[MAX_N];
vector<int> point[MAX_N];
int deg[MAX_N];

void read_input()
{
  cin >> n >> m;
  for(int i=0; i<=n+1; i++) {
    deg[i] = 0;
  }
  point[0].push_back(0);
  point[0].push_back(0);
  point[n+1].push_back(100);
  point[n+1].push_back(100);
  for(int i=1; i<=n; i++) {
    int x,y;
    cin >> x >> y;
    point[i].push_back(x);
    point[i].push_back(y);
  }
  for(int i=0;i<=n;i++){
    for(int j=i+1;j<=n+1;j++){
        if(sqrt(pow(point[i][0]-point[j][0],2)+pow(point[i][1]-point[j][1],2))<=m){
            adj[i].push_back(j);
            adj[j].push_back(i);
            deg[i]++;
            deg[j]++;
        }
    }
  }
}

bool seen[MAX_N];
int layer[MAX_N];

void init()
{
  for(int u = 0; u <= n+1; u++) {
    seen[u] = false;
    layer[u] = -1;
  }
}

void bfs(int s)
{
  vector<int> current_layer;
  vector<int> next_layer;

  current_layer.push_back(s);
  seen[s] = true;
  layer[s] = 0;
  
  while(true) {
    for(vector<int>::iterator i=current_layer.begin(); i!=current_layer.end(); i++) {
      int u = *i;
      for(int d=0; d<deg[u]; d++) {
        int v = adj[u][d];
        if(!seen[v]) {
          next_layer.push_back(v);
          seen[v] = true;
          layer[v] = layer[u] + 1;
        }
      }
    }
    if(next_layer.size() == 0)
      break;

    current_layer = next_layer;
    next_layer.clear();
  }
}


int main(){
    read_input();
    init();
    bfs(0);
    cout << layer[n+1];
    return 0;
}
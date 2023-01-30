#include<iostream>
#include<vector>
#include<list>
using namespace std;
#define MAX_N 200000
int n,m,w,f;
vector<int> adj[MAX_N];
vector<int> warehouse;
vector<int> factory;
vector<int> minimum[MAX_N];
int deg[MAX_N];
vector<bool> ans;

void print_adj(){
    for(int i=0;i<n;i++){
        cout << i << ": ";
        for(int j=0;j<adj[i].size();j++){
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
}

void read_input()
{
  for(int i = 0; i < n; i++)
    deg[i] = 0;
  
  for(int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v; u--; v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  
  for(int i=0;i<w;i++){
    int house;
    cin >> house;
    warehouse.push_back(house-1);
  }

  for(int i=0;i<f;i++){
    int fac;
    cin >> fac;
    factory.push_back(fac-1);
  }

  for(int i=0;i<n;i++){
    minimum[i].push_back(MAX_N);
  }
}

bool seen[MAX_N];
int layer[MAX_N];

void init()
{
  for(int u = 0; u < n; u++) {
    seen[u] = false;
    layer[u] = -1;
  }
}

void bfs(vector<int> adj[]){
    list<int> Q;
    /// find all at the same time
    for(auto i:warehouse){
      Q.push_back(i);
      seen[i] = true;
      layer[i] = 0;
    }
  
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        for(int d=0; d<deg[u]; d++) {
            int v = adj[u][d];
            if(!seen[v]) {
	            Q.push_back(v);
	            seen[v] = true;
	            layer[v] = layer[u] + 1;
            }
        }
    }
    for(auto i :factory){
      minimum[i][0]=min(minimum[i][0],layer[i]);
    }
}

int main(){
    cin >> n >> m >> w >> f;
    read_input();
    init();
    bfs(adj);
    for(auto i :factory){
      cout << minimum[i][0] << '\n';
    }
    return 0;
}
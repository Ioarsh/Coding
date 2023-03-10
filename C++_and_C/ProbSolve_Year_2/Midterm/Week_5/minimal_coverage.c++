#include<iostream>
#include<vector>
#include<list>
using namespace std;
#define MAX_N 200000
int n,m,h;
vector<int> adj[MAX_N];
int deg[MAX_N];
int ans=0;

void print_adj(){
    for(int i=0;i<n;i++){
        for(int j=0;j<adj[i].size();j++){
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
}

void read_input()
{
  cin >> n >> m >> h;
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
void clear(){
    for(int u = 0; u < n; u++) {
    adj[u].clear();
  }
}

int check(vector<int> adj[],int start){
    list<vector<int> > Q;
    int ranges=0;
    int happy=1;

    Q.push_back({start,0});
    seen[start] = true;
  
    while(!Q.empty()) {
        int u = Q.front()[0];
        int round = Q.front()[1];
        if(round==h){
          break;
        }
        Q.pop_front();
        for(int d=0; d<deg[u]; d++) {
            int v = adj[u][d];
            if(!seen[v] && layer[v]==-1) {
	            Q.push_back({v,round+1});
	            seen[v] = true;
              happy+=1;
            }
        }
    }
    return happy;
}

int main(){
    read_input();
    for(int i=0;i<n;i++){
      init();
      int good=check(adj,i);
      if(good>ans){
        ans=good;
      }
    }
    cout << ans;
}
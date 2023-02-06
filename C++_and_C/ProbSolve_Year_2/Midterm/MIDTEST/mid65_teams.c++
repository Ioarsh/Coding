#include<iostream>
#include<vector>
#include<list>
using namespace std;
#define MAX_N 200000
int n,m,k;
vector<int> adj[MAX_N];
int deg[MAX_N];
int color[MAX_N];

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
  cin >> n >> m >> k;
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

bool check(vector<int> adj[],int start){
    list<int> Q;

    Q.push_back(start);
    seen[start] = true;
    layer[start] = 1;
  
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        for(int d=0; d<deg[u]; d++) {
            int v = adj[u][d];
            if(seen[v] && layer[u]==layer[v] && deg[v]<k && deg[u]<k){
                return false;
            }
            if(!seen[v] && layer[v]==-1 && deg[v]<k) {
	            Q.push_back(v);
	            seen[v] = true;
	            layer[v] = 1-layer[u];
            }
        }
    }
    return true;
}

int main(){
    bool ans=true;
    int start;
    read_input();
    init();
    print_adj();
    for(int i=0;i<n;i++){
        if(deg[i]<k){
            ans=check(adj,i);
            if(!ans){
                break;
            }
        }
    }
    if(ans){
        cout << "yes";
    }
    else{
        cout << "no";
    }
    cout << '\n';
    for(int i=0;i<n;i++){
        cout << layer[i] << " ";
    }
}
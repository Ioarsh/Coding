#include<iostream>
#include<vector>
#include<list>
#include<utility>
using namespace std;
#define MAX_N 200000
int n,m;
vector<int> adj[MAX_N];
vector<pair<int,int> > history;
int deg[MAX_N];

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
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    deg[i] = 0;
  
  for(int i = 0; i < m; i++) {
    int u,v;
    cin >> u >> v; u--; v--;

    history.push_back({u,v});
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

bool check_bipartite(int start,int skip){
    list<int> Q;

    Q.push_back(start);
    seen[start] = true;
    layer[start] = 1;
  
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        /*cout << "round: " << u << '\n'; 
        cout << "-----------" << '\n';
        for(int i=0;i<n;i++){
            cout << layer[i] << ' ';
        }
        cout << '\n';
        cout << "-----------" << '\n';*/
        for(auto d:adj[u]) {
            int v = d;
            if(v==skip && u==start){
                //cout << "vertex: " << u << " " << "skip: " << v << '\n';
                if(adj[start].size()==1){
                    return 0;
                }
                continue;
            }
            else if(!seen[v] && layer[v]==-1) {
	            Q.push_back(v);
	            seen[v] = true;
	            layer[v] =  1- layer[u];
            }
        }
    }
    return true;
}

int main(){
    vector<int> out;
    bool ans=0;
    read_input();
    init();
    ///print_adj();
    for(int i=0;i<n;i++){
        for(auto j :adj[i]){
            init();
            ans=check_bipartite(i,j);
            /*cout << "1 bfs" << '\n';
            cout << ans << '\n';*/
            if(ans){
                out.push_back(i+1);
                out.push_back(j+1);
                break;
            }
        }
        if(ans)
            break;
    }
    cout << out[0] << " " << out[1] << "\n";
}
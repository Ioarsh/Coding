#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1000000;

vector<vector<int> > adj[MAX_N];
int deg[MAX_N];
int n,m,h;

void read_input()
{
  cin >> n >> m >> h;
    
  for(int i=0; i<n; i++) {
    deg[i]=0;
  }
  
  for(int i=0; i<m; i++) {
    int u,v,w;
    cin >> u >> v >> w; u--; v--;
    vector<int> way1,way2;
    way1.push_back(v);way1.push_back(w);
    way2.push_back(u);way2.push_back(w);
    adj[u].push_back(way1);
    adj[v].push_back(way2);
    deg[v]++;
    deg[u]++;
  }
}


int dijkstra_onlyfirst()
{
    int dist[n];
    bool visited[n];
    for (int i = 0; i < n; i++){
        dist[i] = MAX_N;
        visited[i]=false;
    }
    dist[0]= 0;
    queue<vector <int> > q;
    q.push({0,0});
    while(!q.empty()){
        int u = q.front()[0];
        q.pop();
        visited[u]=true;
        for(auto i :adj[u]){
            if(dist[i[0]]>dist[u]+i[1]){
                dist[i[0]]=dist[u]+i[1];
                q.push({i[0],dist[i[0]]});
            }
        }
    }
    return dist[n-1];
}

int main(){
    read_input();
    int ans=dijkstra_onlyfirst();
    cout << ans;
}
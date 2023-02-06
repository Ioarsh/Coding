#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;
#define MAX_N 200000
int n,m;
int R,C,A,B,X,Y;
set<int> country;
vector<int> adj[MAX_N];
vector<vector <int> > map;
set<int> graph[MAX_N];
int deg[MAX_N];

void print_adj(){
    for(int i=0;i<country.size();i++){
        cout << i << ": ";
        for(int j=0;j<adj[i].size();j++){
            cout << adj[i][j] << ' ';
        }
        cout << '\n';
    }
}

void new_read_input(){
    cin >> R >> C >> A >> B >> X >> Y;
    for(int i=0;i<R;i++){
        vector<int> row_map;
        for(int j=0;j<C;j++){
            int a;
            cin >> a;
            a--;
            row_map.push_back(a);
            country.insert(a);
        }
        map.push_back(row_map);
    }
    for(auto i: country)
        deg[i] = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(i-1>=0 && map[i-1][j]!=map[i][j]){
                graph[map[i][j]].insert(map[i-1][j]);
            }
            if(i+1<R && map[i+1][j]!=map[i][j]){
                graph[map[i][j]].insert(map[i+1][j]);
            }
            if(j-1>=0 && map[i][j-1]!=map[i][j]){
                graph[map[i][j]].insert(map[i][j-1]);
            }
            if(j+1<C && map[i][j+1]!=map[i][j]){
                graph[map[i][j]].insert(map[i][j+1]);
            }
        }
    }
    for(auto i: country){
        for(auto j:graph[i]){
            adj[i].push_back(j);
            deg[i]++;
        }
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
  for(int u = 0; u <country.size(); u++) {
    seen[u] = false;
    layer[u] = -1;
  }
}
void clear(){
    for(int u = 0; u <country.size(); u++) {
    adj[u].clear();
  }
}

bool check(vector<int> adj[],int start){
    list<int> Q;

    Q.push_back(start);
    seen[start] = true;
    layer[start] = 0;
  
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        for(int d=0; d<adj[u].size(); d++) {
            int v = adj[u][d];
            if(!seen[v]) {
	            Q.push_back(v);
	            seen[v] = true;
	            layer[v] = layer[u] + 1;
            }
        }
    }
    return true;
}

int main(){
    new_read_input();
    init();
    check(adj,map[A-1][B-1]);
    cout << layer[map[X-1][Y-1]];
}
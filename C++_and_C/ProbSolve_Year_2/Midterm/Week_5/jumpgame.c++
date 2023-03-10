#include<iostream>
#include<vector>
#include<list>
using namespace std;
#define MAX_N 1000001
#define MAX_Table 401
int n,m,jump;
vector<int> adj[MAX_Table];
int table[MAX_Table][MAX_Table];
int deg[MAX_Table];
int power[MAX_Table];
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
  cin >> n >> jump;
  for(int i = 0; i < MAX_Table; i++)
    deg[i] = 0;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin >> table[i][j];
        power[i*n+j]=table[i][j];
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i-n>=0){
            int u=(i*n)+j,v=((i-1)*n)+j;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        if(j-1>=0){
            int u=(i*n)+j,v=(i*n)+j-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        if(i+1<n){
            int u=(i*n)+j,v=((i+1)*n)+j;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        if(j+1<n){
            int u=(i*n)+j,v=(i*n)+j+1;
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
    }
  }
}

bool seen[MAX_Table];
int layer[MAX_Table];

void init()
{
  for(int u = 0; u < n*n; u++) {
    seen[u] = false;
    layer[u] = -1;
  }
}
void clear(){
    for(int u = 0; u < n*n; u++) {
    adj[u].clear();
  }
}

bool check(vector<int> adj[],int start){
    list<int> Q;

    Q.push_back(start);
    seen[start] = true;
  
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        for(int d=0; d<deg[u]; d++) {
            int v = adj[u][d];
            if(v==(n*n)-1){
                return true;
            }
            if(!seen[v] && (power[u]>power[v] || abs(power[u]-power[v])<=jump)) {
	            Q.push_back(v);
	            seen[v] = true;
            }
        }
    }
    return false;
}

int main(){
    read_input();
    init();
    bool good=check(adj,0);
    if(good){
        cout << "yes";
    }
    else{
        cout << "no";
    }
}
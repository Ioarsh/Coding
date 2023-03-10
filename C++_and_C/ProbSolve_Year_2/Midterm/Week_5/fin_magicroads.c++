#include<iostream>
#include<vector>
#include<list>
using namespace std;
#define MAX_N 200000
int n,m,h,k;
vector<pair<int,int> > adj[MAX_N];
int magic[MAX_N];
int deg[MAX_N];
int ans=0;

void print_adj(){
}

void read_input()
{
  cin >> n >> m >> k >> h;
  for(int i = 0; i < n; i++){
    deg[i] = 0;
    magic[i]=0;
  }

  for(int i=0;i<k;i++){
    int temp;
    cin >> temp;
    temp--;
    magic[temp]=1;
  }
  
  for(int i = 0; i < m; i++) {
    int u,v,r;
    cin >> u >> v >> r; u--; v--;

    adj[u].push_back({v,r});
    adj[v].push_back({u,r});
    deg[u]++;
    deg[v]++;
  }
}

bool seen[MAX_N];
bool seen_magic[MAX_N];
int layer[MAX_N];

void init()
{
  for(int u = 0; u < n; u++) {
    seen[u] = false;
    seen_magic[u] =false;
    layer[u] = -1;
  }
}
void clear(){
    for(int u = 0; u < n; u++) {
    adj[u].clear();
  }
}

void check(int start){
    list<vector<int> > Q;
    int ranges=0;

    Q.push_back({start,0,magic[start]});
    seen[start] = true;
    seen_magic[start] = magic[start];
  
    while(!Q.empty()) {
        int u = Q.front()[0];
        int round = Q.front()[1];
        int learn = Q.front()[2];
        if(round==h){
          break;
        }
        Q.pop_front();
        for(int d=0; d<deg[u]; d++) {
            int v = adj[u][d].first;
            int is_magic_road = adj[u][d].second;
            if(!seen[v]) {
              if(!learn && !is_magic_road){
                Q.push_back({v,round+1,magic[v]});
	              seen[v] = true;
              }
              else if(learn){
                Q.push_back({v,round+1,learn});
	              seen[v] = true;
                seen_magic[v] = true;
              }
            }
            if(!seen_magic[v] && learn){
              Q.push_back({v,round+1,learn});
              seen[v] = true;
              seen_magic[v] = true;
            }
        }
    }
}

int main(){
    read_input();
    init();
    check(0);
    int ans=0;
    for(int i=0;i<n;i++){
      if(seen[i]){
        ans++;
      }
    }
    cout << ans;
}
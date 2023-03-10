#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
#define MAX_N 200000
int n,m,k,h;
vector<int> adj[MAX_N];
vector<int> hospital;
vector<int> hospital_type;
pair<int,int> type_and_h[MAX_N];
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
  cin >> n >> m >> k >> h;

  for(int i=0;i<k;i++){
    int temp;
    cin >> temp;
    temp--;
    hospital.push_back(temp);
  }

  for(int i=0;i<k;i++){
    int temp;
    cin >> temp;
    temp--;
    hospital_type.push_back(temp);
  }

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

void make_pair(){
    for(int i=0;i<k;i++){
        type_and_h[i].first=hospital_type[i];
        type_and_h[i].second=hospital[i];
     }
}

bool seen[MAX_N];
int layer[MAX_N];

void print_seen(){
    for(int i=0;i<n;i++){
        cout << seen[i] << ' ';
    }
}

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

int check_normal(vector<int> adj[],int start){
    list<vector<int> > Q;
    int ranges=0;
    int happy=0;
    if(!seen[start]){
        happy+=1;
    }

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

int check_fast(vector<int> adj[],int start){
    list<vector<int> > Q;
    int ranges=0;
    int happy=0;
    if(!seen[start]){
        happy+=1;
    }

    Q.push_back({start,0});
    seen[start] = true;
  
    while(!Q.empty()) {
        int u = Q.front()[0];
        int round = Q.front()[1];
        if(round==h*2){
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
    init();
    make_pair();
    sort(type_and_h,type_and_h+k);
    for(int i=k-1;i>=0;i--){
        if(type_and_h[i].first==0){
            ans+=check_fast(adj,type_and_h[i].second);
        }
        else{
            ans+=check_normal(adj,type_and_h[i].second);
        }
    }
    cout << ans;
}
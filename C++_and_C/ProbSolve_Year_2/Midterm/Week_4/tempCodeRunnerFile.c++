#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1000000;

vector<vector<int> > adj[MAX_N];
int deg[MAX_N];
int n,m;

void read_input()
{
  cin >> n >> m;
  if((n == 0) && (m==0))
    return;
    
  for(int i=0; i<n; i++) {
    deg[i]=0;
  }
  
  for(int i=0; i<m; i++) {
    int u,v,w,s;
    cin >> u >> v >> w >> s; u--; v--;
    vector<int> way1,way2;
    way1.push_back(v);way1.push_back(w);way1.push_back(s);
    way2.push_back(u);way2.push_back(w);way2.push_back(s);
    adj[u].push_back(way1);
    adj[v].push_back(way2);
    deg[v]++;
    deg[u]++;
  }
}

struct compare_weight{
    bool operator()(const vector<int>& v1,const vector<int>& v2){
        return v1[1] > v2[1];
    }
};

int dijkstra_onlyfirst()
{
    int dist_noBridge[n],dist_Bridge[n];
    bool visited_noBridge[n],visited_Bridge[n];
    for (int i = 0; i < n; i++){
        dist_noBridge[i] = MAX_N;
        dist_Bridge[i] = MAX_N;
        visited_noBridge[i] = false;
        visited_Bridge[i] =false;
    }
    dist_Bridge[0] = 0;
    dist_noBridge[0] = 0;
    priority_queue<vector<int>,vector<vector<int> >, compare_weight> pq;
    pq.push({0,0,0});
    while(!pq.empty()){
        int u_bridge = pq.top()[2];
        int u = pq.top()[0];
        pq.pop();
        if (u_bridge==1){
            if(visited_Bridge[u])
                continue;
            visited_Bridge[u] = true;
        }
        else{
            if(visited_noBridge[u])
                continue;
            visited_noBridge[u] = true;
        }
        for(auto i :adj[u]){
            // Bridge->NoBridge
            if(u_bridge==1 && i[2]==0){
                if(visited_Bridge[i[0]]==false && dist_Bridge[i[0]]>dist_Bridge[u]+i[0]){
                    dist_Bridge[i[0]]=dist_Bridge[u]+i[1];
                    pq.push({i[0],dist_Bridge[i[0]],1});
                }
            }
            // NoBridge->NoBridge
            else if(u_bridge==0 && i[2]==0){
                if(visited_noBridge[i[0]]==false && dist_noBridge[i[0]]>dist_noBridge[u]+i[0]){
                    dist_noBridge[i[0]]=dist_noBridge[u]+i[1];
                    pq.push({i[0],dist_noBridge[i[0]],0});
                }
            }
            // NoBridge->Bridge
            else if(u_bridge==0 && i[2]==1){
                if(visited_Bridge[i[0]]==false && dist_Bridge[i[0]]>dist_Bridge[u]+i[0]){
                    dist_Bridge[i[0]]=dist_noBridge[u]+i[1];
                    pq.push({i[0],dist_Bridge[i[0]],1});
                }
            }
        }
    }
    if (min(dist_Bridge[n-1],dist_noBridge[n-1])!=MAX_N){
        return min(dist_Bridge[n-1],dist_noBridge[n-1]);
    }
    else return -1;
}

int main(){
    read_input();
    int ans=dijkstra_onlyfirst();
    cout << ans;
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100000;

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
        int u_express = pq.top()[2];
        int u = pq.top()[0];
        int u_weight = pq.top()[1];
        pq.pop();
        if(visited_Bridge[u] && visited_noBridge[u]){
            continue;
        }
        if (u_express==1){
            visited_Bridge[u] = true;
        }
        else{
            visited_noBridge[u] = true;
        }
        for(auto i :adj[u]){
            cout << "queue: " << "{" << u << " " << u_weight << " " << u_express << "}" << "\n";
            cout << "output: \n";
            if(u_express==1 && i[2]!=1){
                if(visited_Bridge[i[0]]==false && dist_Bridge[i[0]]>dist_Bridge[u]){
                    dist_Bridge[i[0]]=dist_Bridge[u]+i[1];
                    pq.push({i[0],dist_Bridge[i[0]],1});
                    cout << "case Bridge->Nobridge: " << i[0] << " " << dist_Bridge[i[0]] << " " << 1 << " " << u_express << " ";
                }
            }
            else if(u_express!=1 && i[2]==0){
                if(visited_noBridge[i[0]]==false && dist_noBridge[i[0]]>dist_noBridge[u]){
                    dist_noBridge[i[0]]=dist_noBridge[u]+i[1];
                    pq.push({i[0],dist_noBridge[i[0]],0});
                    cout << "case Nobridge->Nobridge: " << i[0] << " " << dist_noBridge[i[0]] << " " << 0 << " " << u_express << " ";
                }
            }
            else if(u_express!=1 && i[2]==1){
                if(visited_Bridge[i[0]]==false && dist_Bridge[i[0]]>dist_Bridge[u]){
                    dist_Bridge[i[0]]=dist_noBridge[u]+i[1];
                    pq.push({i[0],dist_Bridge[i[0]],1});
                    cout << "case Nobridge->Bridge: " << i[0] << " " << dist_Bridge[i[0]] << " " << 1 << " " << u_express << " ";
                }
            }
            cout << dist_Bridge[n-1] << ' ' << dist_noBridge[n-1] << "\n";
            cout << "------------------------------------------\n";
        }
    }
    return min(dist_Bridge[n-1],dist_noBridge[n-1]);
}

void print_check(){
    cout << "-------------------\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<deg[i];j++){
            cout << adj[i][j][0] << " " << adj[i][j][1] << " " << adj[i][j][2] << '\n';
        }
        cout << "-------------------\n";
    }
}

int main(){
    read_input();
    int ans=dijkstra_onlyfirst();
    cout << ans;
}
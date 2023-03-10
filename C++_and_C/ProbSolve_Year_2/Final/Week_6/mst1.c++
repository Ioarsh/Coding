#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_N = 1000000;
int n,m;
int mst_int = 0;
int edge[MAX_N][2]; //sort algorithm ของ array บึ้ม X.X เลยมาใช้ pair เก็บ index เอา
pair<int,int>  weight_index[MAX_N];
int parent[MAX_N];
int rank_s[MAX_N];

void read_input(){
    cin >> n >> m;
    
  for(int i=0; i<n; i++) {
    parent[i]=i;
    rank_s[i] = 1;
  }
  
  for(int i=0; i<m; i++) {
    int u,v,w;
    cin >> u >> v >> w; u--; v--;
    edge[i][0]=u;
    edge[i][1]=v;
    weight_index[i].first=w;
    weight_index[i].second=i;
  }
}

int find(int i){
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

void union_set(int u, int v){
        int x = find(u);
        int y = find(v);
        if (x != y) {
            if (rank_s[x] < rank_s[y]) {
                parent[x] = y;
            }
            else if (rank_s[x] > rank_s[y]) {
                parent[y] = x;
            }
            else {
                parent[y] = x;
                rank_s[x] += 1;
            }
        }
    }

void kruskals(){
    sort(weight_index,weight_index+m);
    for(int i=0;i<m;i++){
        int e_index = weight_index[i].second;
        int u = edge[e_index][0];
        int v = edge[e_index][1];

        if(find(u)!=find(v)){
            union_set(u,v);
            mst_int += weight_index[i].first;
        }
    }
    cout << mst_int;
}

int main(){
    read_input();
    kruskals();
}
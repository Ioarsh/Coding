#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX_N = 1000000;
int n,m;
int parent[MAX_N];
int rank_s[MAX_N];
vector<string> ans; 

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

int main(){
    cin >> n >> m;

    for(int i=0; i<n; i++) {
    parent[i]=i;
    rank_s[i] = 1;
    }

    for(int i=0; i<m; i++) {
        int u,v;
        char choice;
        cin >> choice >> u >> v; u--; v--;
        if(choice=='q'){
            if(find(u)==find(v)){
                ans.push_back("yes");
            }
            else
                ans.push_back("no");
        }
        else{
            union_set(u,v);
        }
    }
    for(auto a:ans){
        cout << a << '\n';
    }
}
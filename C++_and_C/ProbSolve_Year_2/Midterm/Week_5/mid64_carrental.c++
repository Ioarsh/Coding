#include<iostream>
#include<vector>
using namespace std;
#define MAX_N 2000000
int k,n;
vector<vector<int> > contract;
vector<int> package;
void read_input(){
    cin >> k >> n;
    for(int i=0;i<k;i++){
        vector<int> con;
        int c,p,w;
        cin >> c >> p >>w;
        con.push_back(c);
        con.push_back(p);
        con.push_back(w);
        contract.push_back(con);
    }
    for(int i=0;i<n;i++){
        int box;
        cin >> box;
        package.push_back(box);
    }
}
int main(void){
    read_input();
    // cout << package.size() << "\n";
    // cout << contract.size() << "\n";
    int min_cost=MAX_N;
    for(auto con:contract){
        int weight_this_set = 0;
        vector<vector <int> > sets;
        for(int i=0;i<n;i++){
            vector<int> set;
            if(package[i]>con[2]){
                sets.clear();
                break;
            }
            if(weight_this_set+package[i]>con[2]){
                // cout << weight_this_set << '\n';
                sets.push_back(set);
                weight_this_set=0;
            }
            set.push_back(package[i]);
            weight_this_set+=package[i];
            if(i==n-1){
                sets.push_back(set);
            }
        }
        int cost=con[0]+(sets.size()*con[1]);
        if(min_cost>cost && !sets.empty()){
            min_cost=cost;
        }
        // cout << sets.size() << " " << min_cost << "\n";
    }
    cout << min_cost;
    return 0;
}
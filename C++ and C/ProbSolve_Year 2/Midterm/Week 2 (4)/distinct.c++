#include<iostream>
#include<set>
#include<list>
using namespace std;
int main(){
    set<int> x;
    list<int> store;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int price;
        cin >> price;
        store.push_back(price);
    }
    for(list<int>::iterator itr=store.begin();itr!=store.end();itr++){
        int temp=0;
        for(list<int>::iterator itr_2=itr;itr_2!=store.end();itr_2++){
            temp+=*itr_2;
            x.insert(temp);
        }
        x.insert(temp);
    }
    cout << x.size() << '\n';
    return(0);
}
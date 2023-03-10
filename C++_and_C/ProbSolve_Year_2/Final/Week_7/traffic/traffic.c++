#include "traffic.h"
#include <vector>
#include <iostream>

using namespace std;
vector<vector<int> > ans;

int n,k;

main()
{
  traffic_init(&n,&k);
  for(int i=1;i<=n;i++){
    int res=traffic_query(i,1,i,n);
    int res_2=traffic_query(1,i,n,i);
    if(res>n-1){
      vector<int> temp;
      temp.push_back(i);temp.push_back(1);temp.push_back(i);temp.push_back(n);
      ans.push_back(temp);
    }
    if(res_2>n-1){
      vector<int> temp;
      temp.push_back(1);temp.push_back(i);temp.push_back(n);temp.push_back(i);
      ans.push_back(temp);
    }
  }
  if(k==1){
    int l_x = ans[0][0], l_y =ans[0][1];
    int r_x = ans[0][2], r_y = ans[0][3];
    int m_x,m_y;
    if(l_x == r_x){
      m_x=l_x;
      while(l_y<r_y){
        m_y = l_y + ((r_y-l_y)/2);
        int find=traffic_query(l_x,l_y,m_x,m_y);
        if(find>m_y-l_y){
            r_y=m_y;
        }
        else{
            l_y=m_y;
        }
        if(r_y-l_y==1){
          break;
        }
      }
    }
    else if(l_y==r_y){
      m_y=l_y;
      while(l_x<r_x){
        m_x=l_x+((r_x-l_x)/2);
        int find=traffic_query(l_x,l_y,m_x,m_y);
        if(find>m_x-l_x){
            r_x=m_x;
        }
        else{
            l_x=m_x;
        }
        if(r_x-l_x==1){
          break;
        }
      }
    }
    traffic_report(l_x,l_y,r_x,r_y,0,0,0,0);
    } 
    else{
      int l_x = ans[0][0], l_y =ans[0][1];
      int r_x = ans[0][2], r_y = ans[0][3];
      int l_x_2 = ans[1][0], l_y_2 =ans[1][1];
      int r_x_2 = ans[1][2], r_y_2 = ans[1][3];
      int m_x,m_y,m_x_2,m_y_2;
      if(l_x == r_x){
        m_x=l_x;
        while(l_y<r_y){
          m_y = l_y + ((r_y-l_y)/2);
          int find=traffic_query(l_x,l_y,m_x,m_y);
          if(find>m_y-l_y){
              r_y=m_y;
          }
          else{
              l_y=m_y;
          }
          if(r_y-l_y==1){
            break;
          }
        }
      }
      else if(l_y==r_y){
        m_y=l_y;
        while(l_x<r_x){
          m_x=l_x+((r_x-l_x)/2);
          int find=traffic_query(l_x,l_y,m_x,m_y);
          if(find>m_x-l_x){
              r_x=m_x;
          }
          else{
              l_x=m_x;
          }
          if(r_x-l_x==1){
            break;
          }
        }
      }
      if(l_x_2 == r_x_2){
        m_x_2=l_x_2;
        while(l_y_2<r_y_2){
          m_y_2 = l_y_2 + ((r_y_2-l_y_2)/2);
          int find=traffic_query(l_x_2,l_y_2,m_x_2,m_y_2);
          if(find>m_y_2-l_y_2){
              r_y_2=m_y_2;
          }
          else{
              l_y_2=m_y_2;
          }
          if(r_y_2-l_y_2==1){
            break;
          }
        }
      }
      else if(l_y_2==r_y_2){
        m_y_2=l_y_2;
        while(l_x_2<r_x_2){
          m_x_2=l_x_2+((r_x_2-l_x_2)/2);
          int find=traffic_query(l_x_2,l_y_2,m_x_2,m_y_2);
          cout << find << ' ' << '\n';
          if(find>m_x_2-l_x_2){
              r_x_2=m_x_2;
          }
          else{
              l_x_2=m_x_2;
          }
          if(r_x_2-l_x_2==1){
            break;
          }
        }
      }
      traffic_report(l_x,l_y,r_x,r_y,l_x_2,l_y_2,r_x_2,r_y_2);
    }
  
}


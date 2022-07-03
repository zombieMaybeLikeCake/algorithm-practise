#include<iostream>
#include<vector>
#include<string>
#include<list>
#include <set>
#include<algorithm>
using namespace std;
int findroot(int a,vector<int> &arry){
   if(arry[a]!=a)
      arry[a]=findroot(arry[a],arry);
   return arry[a];
}
void Union(int a,int b,vector<int> &arry){
      a=findroot(a,arry);
      b=findroot(b,arry);
      if(a!=b){
         arry[b]=a;
      }
}
void inti(vector<int> &arry){
      for(int i=1;i<arry.size();i++){
         arry[i]=i;
      }
}
int main(){
   int m,n,a,b,temp,num=0;
   while(true){
      cin>>n;
      if(n==0){
         break;
      }
      cin>>m;
      vector<int> road;
      road.resize(n+1);
      for(int i=0;i<=n;i++){
         road[i]=i;
      }
      for(int i=0;i<m;i++){
         cin>>a>>b;
         Union(a,b,road);
      }
      for(int i=0;i<=n;i++){
         road[i]=findroot(i,road);
      }
      set<int> s(road.begin(),road.end());
      cout<<s.size()-2<<endl;
   }
   return 0;
}
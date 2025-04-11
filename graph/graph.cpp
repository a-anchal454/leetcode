#include<bits/stdc++.h>
using namespace std;



// UnWeighted Graph 
class Graph{
   public:
   unordered_map<int,list<int>> adj;
   void addEdge(int u,int v){
       adj[u].push_back(v);
       adj[v].push_back(u);
   }

};

class DirectedGraph{
    public:
    unordered_map<int,list<int>> adj;
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }
 
 };


  // Weighted graphs 
 class WeightedGraph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;
    void addEdge(int u,int v,int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }   
 
 };


   // Weighted Directed graphs 
 class WeightedDirectedGraph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;
    void addEdge(int u,int v,int w){
        adj[u].push_back({v,w});
    }   
 
 };


int main(){
      
 

}
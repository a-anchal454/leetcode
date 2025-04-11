## Course Schedule - Cycle Detection in Directed Graph (C++)

### Problem Statement
https://leetcode.com/problems/course-schedule/description/ 

If a cycle exists in the dependency graph, it’s impossible to finish all courses.

This solution uses **Depth First Search (DFS)** with a **cycle detection** mechanism for a directed graph.

### Key Concepts:

- **Visited Map**: To track all visited nodes.
- **DFS Visited Map**: To track nodes visited in the current DFS path (helps in detecting back edges).
- **Adjacency List**: Built from the prerequisites array.
- **Cycle Detection**: If during DFS, a node is revisited that's already in the current path, it indicates a cycle.

```cpp
class Solution {
public:

bool solve (int i, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited, unordered_map<int,list<int>> &adj ){

            visited[i]=1;
            dfsVisited[i]=1;
            for(auto k : adj[i]){
               if(!visited[k]){
                 bool cycle = solve(k,visited,dfsVisited,adj);
                 if(cycle) return true;
               }else{
                  if(dfsVisited[k])
                    return true;
               }
            }
            dfsVisited[i]=0;
            return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,bool> visited,dfsVisited;
        unordered_map<int,list<int>>adj;
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        for(int i=0; i<numCourses; i++){
             if(!visited[i]){
                bool cycle = solve(i,visited,dfsVisited,adj);
                if(cycle) return false; 
             }
               
        }
        return true;
    }
};



# Clone Graph (LeetCode Problem)

This repository contains a C++ solution for the **Clone Graph** problem.

## 🧠 Problem Description
https://leetcode.com/problems/clone-graph/description/ 



#### Solution I  using BFS 
```cpp
  Node* cloneGraph(Node* node) {
       if(node==NULL) return NULL; 
       unordered_map<Node*,Node*> visited;
       visited[node]=new Node(node->val);
       queue<Node*> q;
       q.push(node);
       while(!q.empty()){
          Node* front = q.front();
          q.pop();
          for(auto i:front->neighbors){
            if(visited.find(i)==visited.end()){
                visited[i]=new Node(i->val);
                q.push(i);
            }
           visited[front]->neighbors.push_back(visited[i]);
          }
       }  
       return visited[node];
    }
```
#### Solution II - recursion
```cpp
  Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        visited[node] = new Node(node->val);
        for(auto i : node->neighbors){
            if(visited.find(i)==visited.end()){
                visited[i]=cloneGraph(i);
            } 
            visited[node]->neighbors.push_back(visited[i]); 
        }
        return visited[node];
    }


    
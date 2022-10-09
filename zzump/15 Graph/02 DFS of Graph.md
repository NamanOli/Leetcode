https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#

https://takeuforward.org/data-structure/depth-first-search-dfs-traversal-graph/

https://www.youtube.com/watch?v=uDWljP2PGmU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=8

![image](https://user-images.githubusercontent.com/53824950/161730828-fec6486d-a2e2-485f-8b40-05e934fceb46.png)

![image](https://user-images.githubusercontent.com/53824950/161731182-67da33ff-d513-4203-a327-290b52594f73.png)

```
class Solution {
  public:
  
  void getdfs(vector<int>&vis,vector<int>adj[],int vertex,vector<int>&res)
  {
      if(!vis[vertex])
      {
          vis[vertex]=1;
          res.push_back(vertex);
          for(auto it:adj[vertex])
          {
              getdfs(vis,adj,it,res);
          }
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>res;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                getdfs(vis,adj,0,res);
            }
        }
        return res;
    }
};
```

Time complexity: O(N+E), Where N is the time taken for visiting N nodes and E is for travelling through adjacent nodes.

Space Complexity:O(N+E)+O(N)+O(N) , Space for adjacency list, Array,Auxiliary space.


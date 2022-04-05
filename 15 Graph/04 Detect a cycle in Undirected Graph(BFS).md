https://www.youtube.com/watch?v=A8ko93TyOns&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=9

https://takeuforward.org/data-structure/detect-a-cycle-in-undirected-graph-breadth-first-search/

https://leetcode.com/problems/course-schedule/

https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1/

![image](https://user-images.githubusercontent.com/53824950/161736524-a139a52b-e5b6-4ec0-9217-ba0d9b15908d.png)


![image](https://user-images.githubusercontent.com/53824950/161754526-b77c903d-c824-43ad-8ba2-726fd39b4485.png)

![image](https://user-images.githubusercontent.com/53824950/161755622-35731d87-1429-4d88-baa5-0044371880fa.png)

```
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   public:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int>& visited)
    {
        vector<int> parent(V, -1);
     
        // Create a queue for BFS
        queue<pair<int,int>> q;
     
        visited[s] = true;
        q.push({s, -1});
     
        while (!q.empty()) {
     
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
     
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
public:
	bool isCycle(int V, vector<int>adj[]){
	    vector<int> vis(V, 0); 
	    for(int i = 0;i<V;i++) {
	        if(!vis[i]) {
	            if(checkForCycle(i, V, adj, vis)) return true; 
	        }
	    }
	    
	    return false; 
	}
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
```

Time Complexity: O(N+E),  N is the time taken and E is for traveling through adjacent nodes overall. 

Space Complexity: O(N+E) +  O(N) + O(N) , space for adjacent list , array and queue

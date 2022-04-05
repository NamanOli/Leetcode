https://leetcode.com/problems/course-schedule/discuss/58509/C%2B%2B-BFSDFS

https://leetcode.com/problems/course-schedule/

https://leetcode.com/problems/course-schedule/discuss/658275/C%2B%2B-DFS-Easiest-Solution-With-Explanation-(My-1st-approach)

BFS + Topological Sort - 

```
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(n, vector<int>());
    vector<int> degree(n, 0);
    for (auto &p: prerequisites) {
        adj[p[1]].push_back(p[0]);
        degree[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (degree[i] == 0) q.push(i);
    while (!q.empty()) {
        int curr = q.front(); q.pop(); n--;
        for (auto next: adj[curr])
            if (--degree[next] == 0) q.push(next);
    }
    return n == 0;
    }
};
```
```
bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge : adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i))
                return false;
        }
        return true;
    }
    ```


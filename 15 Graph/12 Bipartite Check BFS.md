https://leetcode.com/problems/is-graph-bipartite/

https://leetcode.com/problems/is-graph-bipartite/discuss/409594/Clean-C%2B%2B-BFS-with-explanation-and-comments

https://www.youtube.com/watch?v=nbgaEu-pvkU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=11

https://github.com/striver79/StriversGraphSeries/blob/main/bipartiteGraphCppBfs

![image](https://user-images.githubusercontent.com/53824950/161834005-aa9b9000-7ce9-47f6-95c0-ebe6021b7d99.png)

Graph Based -

```
#include <bits/stdc++.h>
using namespace std;

bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    queue<int>q;
    q.push(src); 
    color[src] = 1; 
    while(!q.empty()) {
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; 
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; 
            }
        }
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	
	if(checkBipartite(adj, n)) {
	    cout << "yes"; 
	} else {
	    cout << "No"; 
	}
	return 0;
}

/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/ 

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/



```


Grid Based - 

```
 bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n); // 0: uncolored; 1: color A; -1: color B
        
    queue<int> q; // queue, resusable for BFS    
	
    for (int i = 0; i < n; i++) {
      if (color[i]) continue; // skip already colored nodes
      
      // BFS with seed node i to color neighbors with opposite color
      color[i] = 1; // color seed i to be A (doesn't matter A or B) 
      for (q.push(i); !q.empty(); q.pop()) {
        int cur = q.front();
        for (int neighbor : graph[cur]) 
		{
          if (!color[neighbor]) // if uncolored, color with opposite color
          { color[neighbor] = -color[cur]; q.push(neighbor); } 
		  
          else if (color[neighbor] == color[cur]) 
            return false; // if already colored with same color, can't be bipartite!
        }        
      }
    }
    
    return true;
  }
  ```

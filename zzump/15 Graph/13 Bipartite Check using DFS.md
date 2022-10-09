https://takeuforward.org/data-structure/bipartite-check-using-dfs-if-graph-is-bipartite/

https://leetcode.com/problems/is-graph-bipartite/

https://www.youtube.com/watch?v=uC884ske2uQ&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12

https://github.com/striver79/StriversGraphSeries/blob/main/bipartiteGraphCppDfs

![image](https://user-images.githubusercontent.com/53824950/161890442-d724c691-2d31-4805-bb20-d252c5432508.png)


```
class Solution {
    public:
    bool checkbipartite(int node,vector<vector<int>>& graph,int color[])
    {
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                if(!checkbipartite(it,graph,color))
                {
                    return false;
                }
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int color[n];
        memset(color,-1,sizeof color);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=1;
            }
            if(!checkbipartite(i,graph,color))
            {
                return false;
            }
        }
        return true;
    }
};
```


Time Complexity: O(V + E), since in its whole, it is a DFS implementation, V – vertices; E – edges;

Space Complexity: O(V), because, apart from the graph, we maintain a color array.
